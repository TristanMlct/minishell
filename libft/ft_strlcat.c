/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:07:13 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/09 11:11:47 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len_s;
	size_t	len_d;

	len_d = 0;
	if (!dest && n == 0)
		return (0);
	while (dest[len_d] && len_d < n)
		len_d++;
	len_s = ft_strlen(src);
	i = 0;
	if (n > 0 && len_d < n - 1)
	{
		while (src[i] && i + len_d < n - 1)
		{
			dest[len_d + i] = src[i];
			i++;
		}
		dest[len_d + i] = '\0';
	}
	return (len_s + len_d);
}
