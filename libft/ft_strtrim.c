/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:27:20 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/12 13:25:47 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char c, char const *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		start;
	int		end;
	int		len_str;
	int		i;
	char	*r;

	if (!str)
		return (0);
	start = 0;
	while (str[start] && is_in_charset(str[start], set))
		start++;
	len_str = ft_strlen(str);
	end = len_str - 1;
	while (end >= 0 && is_in_charset(str[end], set))
		end--;
	if (end < start)
		end = start - 1;
	r = malloc((end - start + 2) * sizeof(char));
	if (!r)
		return (0);
	i = -1;
	while (++i + start <= end)
		r[i] = str[start + i];
	r[i] = '\0';
	return (r);
}
