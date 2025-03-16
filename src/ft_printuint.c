/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:16:42 by takawauc          #+#    #+#             */
/*   Updated: 2025/03/16 14:43:43 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putuint(unsigned int num)
{
	char	c;

	if (num < 10)
	{
		c = num + '0';
		if (-1 == write(STDOUT_FILENO, &c, 1))
			return (-1);
	}
	else
	{
		c = num % 10 + '0';
		if (-1 == ft_putuint(num / 10) || -1 == write(STDOUT_FILENO, &c, 1))
			return (-1);
	}
	return (0);
}

int	ft_uintlen(unsigned int num)
{
	int	ret;

	ret = 1;
	while (num > 9)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

int	ft_printuint(unsigned int num)
{
	if (-1 == ft_putuint(num))
		return (-1);
	return (ft_uintlen(num));
}
