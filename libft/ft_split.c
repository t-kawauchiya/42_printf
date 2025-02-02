/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TakeshiKawauchiya <TakeshiKawauchiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:19:26 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2024/11/30 23:42:09 by TakeshiKawa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c);
static char		**ft_alloc_array(char const *s, char c, size_t word_count);
static void		*ft_free_allay(char **ret, size_t i);

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = ft_alloc_array(s, c, ft_word_count(s, c));
	return (ret);
}

static char	**ft_alloc_array(char const *s, char c, size_t word_count)
{
	size_t	word_len;
	size_t	i;
	char	**ret;

	ret = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		if (!word_len)
			break ;
		ret[i] = ft_substr(s, 0, word_len);
		if (!ret[i])
			return (ft_free_allay(ret, i));
		s += word_len;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	*ft_free_allay(char **ret, size_t i)
{
	while (i > 0)
	{
		i--;
		free(ret[i]);
	}
	free(ret);
	return (NULL);
}
