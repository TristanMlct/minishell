/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:14:06 by mhug              #+#    #+#             */
/*   Updated: 2022/11/08 13:45:35 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_index_of(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			return (i);
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0' && ft_index_of(set, *s1) != -1)
		++s1;
	len = ft_strlen(s1);
	while (len && ft_index_of(set, s1[len - 1]) != -1)
		--len;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}
