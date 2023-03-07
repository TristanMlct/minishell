/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:50:37 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:09:36 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnb_n(long nb, int len)
{
	char	c;

	if (nb < 0)
		nb *= -1;
	if (len > 0)
		ft_putnb_n(nb / 10, len - 1);
	if (len > 0)
	{
		c = (nb % 10) + '0';
		write(1, &c, 1);
	}
}

int	get_nb_len(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
		nb *= -1;
	while (nb / 10)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

char	*get_prefix(t_printf *p, int nb)
{
	if (nb < 0)
		return ("-");
	else if (p->flags.sign_prefix == 1)
		return ("+");
	else if (p->flags.space_prefix == 1)
		return (" ");
	return (NULL);
}

void	ft_print_int(t_printf *p, va_list args)
{
	long	nb;
	int		len;
	char	*prefix;

	nb = (int)va_arg(args, int);
	len = get_nb_len(nb);
	prefix = get_prefix(p, nb);
	if (len < p->flags.precision || (!p->flags.precision && !nb))
		len = p->flags.precision;
	if (prefix)
		++len;
	if (p->flags.zero_padding && len < p->flags.width)
		len = p->flags.width;
	if (!p->flags.left_justify && p->flags.width)
		print_padd(p, len);
	if (prefix)
	{
		write(1, prefix, 1);
		ft_putnb_n(nb, len - 1);
	}
	else
		ft_putnb_n(nb, len);
	if (p->flags.left_justify && p->flags.width)
		print_padd(p, len);
	p->len += len;
}

void	ft_print_uint(t_printf *p, va_list args)
{
	long	nb;
	int		len;

	nb = (unsigned int)va_arg(args, unsigned int);
	len = get_nb_len(nb);
	if (len < p->flags.precision || (!p->flags.precision && !nb))
		len = p->flags.precision;
	if (p->flags.zero_padding && len < p->flags.width)
		len = p->flags.width;
	if (!p->flags.left_justify && p->flags.width)
		print_padd(p, len);
	ft_putnb_n(nb, len);
	if (p->flags.left_justify && p->flags.width)
		print_padd(p, len);
	p->len += len;
}
