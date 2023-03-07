/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:12:09 by mhug              #+#    #+#             */
/*   Updated: 2022/11/08 19:33:15 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t			i;

	if (!src || !dest)
		return (NULL);
	c_src = (unsigned char *)src;
	c_dest = (unsigned char *)dest;
	if (c_src < c_dest && (c_src + len > c_dest))
	{
		while (len--)
			c_dest[len] = c_src[len];
	}
	else
	{
		i = -1;
		while (++i < len)
			c_dest[i] = c_src[i];
	}
	return (dest);
}
