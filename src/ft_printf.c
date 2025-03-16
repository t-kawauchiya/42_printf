/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:02:37 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/02/21 21:32:42 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printstr(char *str)
{
	int	ret;

	ret = 0;
	if (!str)
		str = "(null)";
	while (str[ret])
		ret++;
	return (write(1, str, ret));
}

int	ft_printchar(int num)
{
	char	c;

	c = (char)num;
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_format(const char format, va_list args)
{
	int	ret;

	ret = 0;
	if ('c' == format)
		ret = ft_printchar(va_arg(args, int));
	else if ('s' == format)
		ret = ft_printstr(va_arg(args, char *));
	else if ('p' == format)
		ret = ft_printptr(va_arg(args, char *));
	else if ('d' == format || 'i' == format)
		ret = ft_printint(va_arg(args, int));
	else if ('u' == format)
		ret = ft_printuint(va_arg(args, unsigned int));
	else if ('x' == format || 'X' == format)
		ret = ft_printhex(va_arg(args, unsigned int), format);
	else
		ret = ft_printchar('%');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		outputlen;

	ret = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if ('%' == *format)
		{
			outputlen = ft_format(*(format + 1), args);
			format++;
		}
		else
			outputlen = ft_printchar(*format);
		format++;
		if (-1 == outputlen)
			return (-1);
		ret += outputlen;
	}
	va_end(args);
	return (ret);
}
