/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:33:41 by takawauc          #+#    #+#             */
/*   Updated: 2025/02/01 15:11:10 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_puthex(unsigned int num, char format)
{
	if (num > 15)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else if (num > 9)
		ft_putchar_fd(num - 10 + format + 'a' - 'x', STDOUT_FILENO);
	else
		ft_putchar_fd(num + '0', STDOUT_FILENO);
}

int	ft_hexlen(unsigned int num)
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

int	ft_printhex(unsigned int num, char format)
{
	int	ret;

	ret = 0;
	ret = ft_hexlen(num);
	ft_puthex(num, format);
	return (ret);
}
