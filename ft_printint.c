/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:14:15 by takawauc          #+#    #+#             */
/*   Updated: 2025/01/31 21:30:04 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

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
