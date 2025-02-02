/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:16:42 by takawauc          #+#    #+#             */
/*   Updated: 2025/01/31 21:17:37 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

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

	ret = ft_uintlen(num);
	ft_putuint(num);
	return (ret);
}
