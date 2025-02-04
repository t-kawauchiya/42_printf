/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:12:00 by takawauc          #+#    #+#             */
/*   Updated: 2025/02/02 18:43:23 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putptr(uintptr_t num)
{
	char	c;

	if (num < 10)
	{
		c = '0' + num;
		return (write(STDOUT_FILENO, &c, 1));
	}
	else if (num < 16)
	{
		c = 'a' + num - 10;
		return (write(STDOUT_FILENO, &c, 1));
	}
	if (-1 == ft_putptr(num / 16) || -1 == ft_putptr(num % 16))
		return (-1);
	return (0);
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
