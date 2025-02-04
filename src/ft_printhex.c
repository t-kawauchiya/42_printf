/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:33:41 by takawauc          #+#    #+#             */
/*   Updated: 2025/02/02 19:04:27 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_puthex(unsigned int num, char format)
{
	char	c;

	if (num > 15)
	{
		if (-1 == ft_puthex(num / 16, format) || -1 == ft_puthex(num % 16,
				format))
			return (-1);
	}
	else if (num > 9)
	{
		c = num - 10 + format + 'a' - 'x';
		return (write(STDOUT_FILENO, &c, 1));
	}
	else
	{
		c = num + '0';
		return (write(STDOUT_FILENO, &c, 1));
	}
	return (0);
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

	if (-1 == ft_puthex(num, format))
		return (-1);
	ret = ft_hexlen(num);
	return (ret);
}
