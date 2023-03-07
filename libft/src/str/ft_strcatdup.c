/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:37:03 by mhug              #+#    #+#             */
/*   Updated: 2023/01/08 16:37:21 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatdup(char *buf1, char *buf2, int free1, int free2)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(buf1);
	len2 = ft_strlen(buf2);
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len1)
		new[i] = buf1[i];
	j = -1;
	while (++j < len2)
		new[i + j] = buf2[j];
	new[i + j] = '\0';
	if (free1 && buf1)
		free(buf1);
	if (free2 && buf2)
		free(buf2);
	return (new);
}
