/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:02:37 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/01/30 20:55:50 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"
#include <stdarg.h>

int		ft_format(char format, va_list args);

int	ft_printpercent(void)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

void	ft_puthex(int num, char format)
{
	if (num > 15)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else if (num > 9)
		ft_putchar_fd(num - 10 + format + 'a' - 'x', 1);
	else
		ft_putchar_fd(num + '0', STDOUT_FILENO);
}

int	ft_hexlen(int num)
{
	int	ret;

	ret = 0;
	while (num > 15)
	{
		num /= 16;
		ret++;
	}
	ret++;
	return (ret);
}

int	ft_printhex(int num, char format)
{
	int	ret;

	ret = 0;
	ret = ft_hexlen(num);
	ft_puthex(num, format);
	return (ret);
}

int	ft_printstr(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
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
	while (num > 15)
	{
		num /= 16;
		ret++;
	}
	ret++;
	return (ret);
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
		ret += ft_ptrlen(n);
	}
	return (ret);
}

int	ft_intlen(int num)
{
	int	ret;

	ret = 0;
	if (num == INT_MIN)
		return (11);
	if (num < 0)
	{
		ret++;
		num = -num;
	}
	while (num > 9)
	{
		num /= 10;
		ret++;
	}
	ret++;
	return (ret);
}

void	ft_putint(int num)
{
	if (num == INT_MIN)
	{
		ft_putstr_fd("-2147483648", 1);
		return ;
	}
	else if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	if (num < 10)
		ft_putchar_fd(num + '0', 1);
	else
	{
		ft_putint(num / 10);
		ft_putchar_fd(num % 10 + '0', 1);
	}
}

int	ft_printint(int num)
{
	int	ret;

	ret = ft_intlen(num);
	ft_putint(num);
	return (ret);
}

void	ft_putuint(unsigned int num)
{
	if (num < 10)
	{
		ft_putchar_fd(num + '0', 1);
	}
	else
	{
		ft_putint(num / 10);
		ft_putchar_fd(num % 10 + '0', 1);
	}
}

int	ft_uintlen(unsigned int num)
{
	int	ret;

	ret = 0;
	while (num > 9)
	{
		num /= 10;
		ret++;
	}
	ret++;
	return (ret);
}

int	ft_printuint(unsigned int num)
{
	int	ret;

	ret = ft_intlen(num);
	ft_putuint(num);
	return (ret);
}

int	ft_format(char format, va_list args)
{
	int	ret;

	ret = 0;
	if ('c' == format)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ret = 1;
	}
	else if ('s' == format)
		ret = ft_printstr(va_arg(args, char *));
	else if ('p' == format)
		ret = ft_printptr(va_arg(args, unsigned long long));
	else if ('d' == format || 'i' == format)
		ret = ft_printint(va_arg(args, int));
	else if ('u' == format)
		ret = ft_printuint(va_arg(args, unsigned int));
	else if ('x' == format || 'X' == format)
		ret = ft_printhex(va_arg(args, unsigned int), format);
	else if ('%' == format)
		ret = ft_printpercent();
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if ('%' == format[i])
		{
			ret += ft_format(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			ret++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}

// int	main(void)
// {
// 	ft_putendl_fd("----------------", 1);
// 	ft_putnbr_fd(ft_printf("abc"), 1);
// 	ft_putendl_fd("----------------", 1);
// }
