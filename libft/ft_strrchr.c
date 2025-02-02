/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:04:40 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2024/12/01 10:18:49 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cptr;

	cptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			cptr = (char *)s;
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (cptr);
}
