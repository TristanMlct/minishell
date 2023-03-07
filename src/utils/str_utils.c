/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:28:12 by mhug              #+#    #+#             */
/*   Updated: 2023/03/07 13:04:53 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_only_spaces(char *str)
{
	while (str && *str)
	{
		if (!ft_isspace(*str))
			return (0);
		++str;
	}
	return (1);
}

char	**ft_split_first(char *str, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str || !*str)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * 3);
	if (!arr)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == c)
		{
			arr[j] = ft_substr(str, 0, i);
			arr[++j] = ft_substr(str, i + 1, ft_strlen(str) - i);
			arr[++j] = NULL;
			return (arr);
		}
	}
	arr[0] = ft_strdup(str);
	arr[1] = NULL;
	return (arr);
}
