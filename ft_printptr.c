/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:12:00 by takawauc          #+#    #+#             */
/*   Updated: 2025/02/01 15:40:49 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putptr(uintptr_t num)
{
	if (num > 15)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else if (num > 9)
		ft_putchar_fd('a' + num - 10, STDOUT_FILENO);
	else
		ft_putchar_fd('0' + num, STDOUT_FILENO);
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
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (ft_strlen("(nil)"));
	}
	num = (unsigned long long)ptr;
	ret = 0;
	ret += write(1, "0x", 2);
	if (num == 0)
		ret += write(1, "0", 1);
	else
	{
		ft_putptr(num);
		ret += ft_ptrlen(num);
	}
	return (ret);
}
