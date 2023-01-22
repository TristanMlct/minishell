/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:18:25 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/09 18:36:40 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	in_word;
	int	count;
	int	i;

	count = 0;
	in_word = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
	}
	return (count);
}

static char	*next_word(const char *s, int word_len, int curr_pos)
{
	char	*r;
	int		i;

	r = malloc((word_len + 1) * sizeof(char));
	i = -1;
	while (++i < word_len)
		r[i] = s[curr_pos - word_len + i];
	r[i] = '\0';
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word_nbr;
	int		word_len;
	int		curr_pos;

	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab || !s)
		return (0);
	curr_pos = -1;
	word_nbr = -1;
	while (s[++curr_pos])
	{
		word_len = 0;
		if (s[curr_pos] != c)
		{
			word_nbr++;
			curr_pos--;
			while (s[++curr_pos] != c && s[curr_pos])
				word_len++;
			tab[word_nbr] = next_word(s, word_len, curr_pos);
			curr_pos--;
		}
	}
	tab[word_nbr + 1] = 0;
	return (tab);
}
