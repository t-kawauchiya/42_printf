/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 02:09:18 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2024/12/01 01:48:14 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_(int n);
static size_t	ft_get_len(int n);

char	*ft_itoa(int n)
{
	char	*ret;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ret = ft_itoa_(n);
	return (ret);
}

static size_t	ft_get_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	else if (n == 0)
	{
		return (1);
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_(int n)
{
	char	*ret;
	int		is_negative;
	size_t	len;

	is_negative = 0;
	len = ft_get_len(n);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		is_negative = 1;
		n *= -1;
	}
	while (len - is_negative)
	{
		ret[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (ret);
}
