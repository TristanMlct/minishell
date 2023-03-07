/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:06 by mhug              #+#    #+#             */
/*   Updated: 2022/11/08 13:46:31 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_len(int nb)
{
	int	len;

	len = 1;
	while (nb / 10)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	lnb;
	char	*nb_str;
	int		is_negative;
	int		len;

	lnb = (long)n;
	is_negative = 0;
	if (lnb < 0)
	{
		is_negative = 1;
		lnb *= -1;
	}
	len = get_nb_len(lnb) + is_negative;
	nb_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb_str)
		return (NULL);
	nb_str[len] = '\0';
	while (lnb || len == 1)
	{
		nb_str[--len] = (char)(lnb % 10 + '0');
		lnb /= 10;
	}
	if (is_negative)
		nb_str[0] = '-';
	return (nb_str);
}
