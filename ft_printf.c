/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:02:37 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/01/26 21:28:19 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int		ft_format(char format, va_list args);

int	ft_printf(const char *format, ...)
{
	int		i;
	void	*hoge;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if ('%' == format[i])
		{
			ft_format(format[i + 1], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (0);
}

int	ft_format(char format, va_list args)
{
	int		ret;
	char	*str;

	ret = 0;
	if ('c' == format)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ret = 1;
	}
	else if ('s' == format)
		ret = ft_printstr(va_arg(args, char *));
	else if ('p' == format)
		ret = ft_putptr(va_arg(args, unsigned long long));
	else if ('d' == format || 'i' == format)
		ret = ft_printnbr(va_arg(args, int));
	else if ('u' == format)
		ret = ft_printhex(va_arg(args, int));
	else if ('x' == format)
		ret = ft_printhex(va_arg(args, int), 0);
	else if ('X' == format)
		ret = ft_printhex(va_arg(args, int), 1);
	else if ('%' == format)
		ret = ft_printpercent();
	return (ret);
}

int	ft_printstr(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printptr(unsigned long long n)
{
	int	ret;

	ret = 0;
	ret += write(1, "0x", 2);
	if (n == 0)
		ret += write(1, "0", 1);
	else
	{
		ft_putptr(n);
		ft_ptrlen(n);
	}
	return (ret);
}

void	ft_putptr(uintptr_t num)
{
	if (num > 15)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else if (num > 9)
		ft_putchar_fd('a' + num - 10, 1);
	else
		ft_putchar_fd('0' + num, 1);
}

int	ft_ptrlen(uintptr_t num)
{
	int	ret;

	ret = 0;
	while (!num)
	{
		num /= 16;
		ret++;
	}
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", "abc");
// 	printf("%p", "abc");
// }
