/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:12:20 by mhug              #+#    #+#             */
/*   Updated: 2022/11/08 13:14:28 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	lnb;

	lnb = (long)n;
	if (lnb < 0)
	{
		ft_putchar_fd('-', fd);
		lnb *= -1;
	}
	if (lnb > 9)
		ft_putnbr_fd(lnb / 10, fd);
	ft_putchar_fd(lnb % 10 + '0', fd);
}
