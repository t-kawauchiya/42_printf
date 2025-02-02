/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:50:13 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2024/11/30 22:02:56 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	if (!len || (!dst && !src))
		return (dst);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
		return (dst);
	}
	i = len;
	while (i > 0)
	{
		cdst[i - 1] = csrc[i - 1];
		i--;
	}
	return (dst);
}
