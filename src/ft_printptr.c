/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:12:00 by takawauc          #+#    #+#             */
/*   Updated: 2025/03/16 14:43:16 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putptr(uintptr_t num)
{
	char	*hex_base_str;

	hex_base_str = "0123456789abcdef";
	if (num < 16)
	{
		return (write(STDOUT_FILENO, &hex_base_str[num], 1));
	}
	if (-1 == ft_putptr(num / 16) || -1 == ft_putptr(num % 16))
		return (-1);
	return (0);
}

int	ft_ptrlen(uintptr_t num)
{
	int	ret;

	ret = 1;
	while (num > 15)
	{
		num /= 16;
		ret++;
	}
	return (ret);
}

int	ft_printptr(char *ptr)
{
	int			ret;
	uintptr_t	num;

	if (!ptr)
		return (ft_printstr("(nil)"));
	num = (unsigned long long)ptr;
	if (-1 == write(1, "0x", 2))
		return (-1);
	ret = 2;
	if (num == 0)
	{
		if (-1 == write(1, "0", 1))
			return (-1);
		ret++;
	}
	else
	{
		if (-1 == ft_putptr(num))
			return (-1);
		ret += ft_ptrlen(num);
	}
	return (ret);
}
