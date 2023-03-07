/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:41:27 by mhug              #+#    #+#             */
/*   Updated: 2022/11/27 14:08:27 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_prefix(const char *str, int base)
{
	int	i;

	i = 0;
	if (base == 2 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (1);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
	}
	return (0);
}

static int	index_in_base(char c, int base)
{
	char	*b_lower;
	char	*b_upper;
	int		i;

	b_lower = "0123456789abcdef";
	b_upper = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == b_lower[i] || c == b_upper[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int		nb;
	int		index;

	nb = 0;
	if (base == 10)
		return (ft_atoi(str));
	while (ft_isspace(*str))
		++str;
	if (has_prefix(str, base))
		str += 2;
	while (*str != '\0')
	{
		index = index_in_base(*str, base);
		if (index == -1)
			break ;
		nb = (nb * base) + index;
		++str;
	}
	return ((int)nb);
}
