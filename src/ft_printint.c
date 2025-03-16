/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:14:15 by takawauc          #+#    #+#             */
/*   Updated: 2025/02/21 21:33:22 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

int	ft_putint(int num)
{
	char	c;

	if (num == INT_MIN)
		return (write(STDOUT_FILENO, "-2147483648", 11));
	if (num < 0)
	{
		c = '-';
		if (-1 == write(STDOUT_FILENO, &c, 1))
			return (-1);
		num = -num;
	}
	if (num < 10)
	{
		c = num + '0';
		if (-1 == write(STDOUT_FILENO, &c, 1))
			return (-1);
	}
	else
	{
		c = num % 10 + '0';
		if (-1 == ft_putint(num / 10) || -1 == write(STDOUT_FILENO, &c, 1))
			return (-1);
	}
	return (0);
}

int	ft_printint(int num)
{
	int	ret;

	if (-1 == ft_putint(num))
		return (-1);
	ret = ft_intlen(num);
	return (ret);
}
