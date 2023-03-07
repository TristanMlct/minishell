/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:59:52 by mhug              #+#    #+#             */
/*   Updated: 2022/12/03 12:02:19 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
     clamps a value between an upper and lower bound
*/

#include "libft.h"

int	ft_clamp(int n, int min, int max)
{
	if (n < min)
		return (min);
	else if (n < max)
		return (max);
	return (n);
}
