/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:23:26 by mhug              #+#    #+#             */
/*   Updated: 2022/12/03 11:54:11 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	nb = 0;
	while (ft_isdigit(*str))
	{
		nb = (nb * 10) + (*str - '0');
		++str;
	}
	return ((long)(sign * nb));
}
