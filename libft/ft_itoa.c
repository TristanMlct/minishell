/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 00:14:10 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/09 18:36:04 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int			c;
	long int	copy;

	c = 0;
	copy = n;
	if (n < 0)
	{
		c++;
		copy *= -1;
	}
	while (copy / 10 != 0)
	{
		c++;
		copy /= 10;
	}
	return (c + 1);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			size;
	int			min;
	long int	copy;

	size = nbr_len(n);
	s = malloc((size + 1) * sizeof(char));
	if (!s)
		return (0);
	s[size] = '\0';
	min = 0;
	copy = n;
	if (n < 0 && ++min)
	{
		s[0] = '-';
		copy *= -1;
	}
	if (size == 1 && copy == 0)
		s[0] = '0';
	while (copy != 0 && --size >= min)
	{
		s[size] = (copy % 10) + '0';
		copy /= 10;
	}
	return (s);
}
