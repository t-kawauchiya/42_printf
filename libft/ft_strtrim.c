/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:55:06 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2024/11/30 21:20:51 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isincludedinset(const char c, const char *set);
// static size_t	calclength(const char *s1, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && isincludedinset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (start < end && s1[end - 1] && isincludedinset(s1[end - 1], set))
		end--;
	ret = malloc((end - start + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		ret[i] = s1[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// static size_t	calclength(const char *s, const char *set)
// {
// 	size_t	i;
// 	size_t	len;

// 	len = ft_strlen(s);
// 	i = 0;
// 	while (s[i] && isincludedinset(s[i], set))
// 	{
// 		len--;
// 		i++;
// 	}
// 	if (len == 0)
// 		return (0);
// 	i = len - 1;
// 	while (s[i] && isincludedinset(s[i], set))
// 	{
// 		len--;
// 		i--;
// 	}
// 	return (len);
// }

static int	isincludedinset(const char c, const char *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
