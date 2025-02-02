/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:02:37 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/02/01 15:35:35 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_format(char format, va_list args);

int	ft_printpercent(void)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

int	ft_printstr(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
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
		ret = ft_printptr(va_arg(args, char *));
	else if ('d' == format || 'i' == format)
		ret = ft_printint(va_arg(args, int));
	else if ('u' == format)
		ret = ft_printuint(va_arg(args, unsigned int));
	else if ('x' == format || 'X' == format)
	{
		ret = ft_printhex(va_arg(args, unsigned int), format);
	}
	else
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
