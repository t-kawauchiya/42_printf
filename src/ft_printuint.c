/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:16:42 by takawauc          #+#    #+#             */
/*   Updated: 2025/02/21 21:33:51 by takawauc         ###   ########.fr       */
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

	if (-1 == ft_putuint(num))
		return (-1);
	ret = ft_uintlen(num);
	return (ret);
}
