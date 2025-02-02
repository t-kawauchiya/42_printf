/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:27:49 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2024/11/28 02:34:50 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1len;
	char	*result;
	size_t	i;

	s1len = ft_strlen(s1);
	result = (char *)malloc((s1len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
