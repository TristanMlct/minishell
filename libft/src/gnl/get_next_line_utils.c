/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:39:27 by mhug              #+#    #+#             */
/*   Updated: 2022/11/30 15:58:36 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_strs(char **str1, char **str2)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}

int	ft_index_of(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_strnjoin(char *s1, char *s2, int s1_len, int s2_len)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	j = -1;
	while (++j < s2_len)
		str[i + j] = s2[j];
	str[s1_len + s2_len] = '\0';
	if (s1)
		free(s1);
	return (str);
}
