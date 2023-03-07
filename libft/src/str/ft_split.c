/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:12:36 by mhug              #+#    #+#             */
/*   Updated: 2022/11/08 13:48:04 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char sep)
{
	int	n_words;

	n_words = 0;
	while (*s != '\0')
	{
		if (*s != sep)
		{
			++n_words;
			while (*s != '\0' && *s != sep)
				++s;
		}
		else
			++s;
	}
	return (n_words);
}

static int	add_str_to_tab(char **tab, char const *str, char sep, size_t *w_len)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != sep)
		++len;
	*tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!*tab)
		return (0);
	ft_memcpy(*tab, str, len);
	(*tab)[len] = '\0';
	*w_len = len;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;
	size_t	i;
	size_t	w_len;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s != '\0' && *s == c)
			++s;
		if (!add_str_to_tab(tab + i++, s, c, &w_len))
			return (NULL);
		s += w_len;
	}
	tab[size] = 0;
	return (tab);
}
