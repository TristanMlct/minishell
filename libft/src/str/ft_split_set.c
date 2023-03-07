/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:11:17 by mhug              #+#    #+#             */
/*   Updated: 2022/11/30 22:11:35 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static int	count_words(char const *s, char *set)
{
	int	n_words;

	n_words = 0;
	while (*s != '\0')
	{
		if (!is_in_set(*s, set))
		{
			++n_words;
			while (*s != '\0' && !is_in_set(*s, set))
				++s;
		}
		else
			++s;
	}
	return (n_words);
}

static int	add_str_to_tab(char **tab, char const *str,
			char *set, size_t *w_len)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && !is_in_set(str[len], set))
		++len;
	*tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!*tab)
		return (0);
	ft_memcpy(*tab, str, len);
	(*tab)[len] = '\0';
	*w_len = len;
	return (1);
}

char	**ft_split_set(char const *s, char *set)
{
	char	**tab;
	size_t	size;
	size_t	i;
	size_t	w_len;

	if (!s)
		return (NULL);
	size = count_words(s, set);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s != '\0' && is_in_set(*s, set))
			++s;
		if (!add_str_to_tab(tab + i++, s, set, &w_len))
			return (NULL);
		s += w_len;
	}
	tab[size] = 0;
	return (tab);
}
