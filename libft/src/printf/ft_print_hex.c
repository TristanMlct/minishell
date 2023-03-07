/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:10:59 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:09:24 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexnb_n(unsigned long long nb, int len, char spec)
{
	char	*base;

	if (spec == 'x' || spec == 'p')
		base = "0123456789abcdef";
	else if (spec == 'X')
		base = "0123456789ABCDEF";
	if (len > 0)
		ft_puthexnb_n(nb / 16, len - 1, spec);
	if (len > 0)
		write(1, &base[nb % 16], 1);
}

int	get_hexnb_len(unsigned long long nb)
{
	int	len;

	len = 1;
	while (nb / 16)
	{
		nb /= 16;
		++len;
	}
	return (len);
}

char	*get_prefix_base(t_printf *p, unsigned int hex_nb)
{
	if (hex_nb && p->spec == 'x' && p->flags.base_prefix)
		return ("0x");
	else if (hex_nb && p->spec == 'X' && p->flags.base_prefix)
		return ("0X");
	return (NULL);
}

void	ft_print_hex(t_printf *p, va_list args)
{
	unsigned int	nb;
	int				len;
	char			*prefix;

	nb = (unsigned int)va_arg(args, unsigned int);
	prefix = get_prefix_base(p, nb);
	len = get_hexnb_len(nb);
	if (len < p->flags.precision || (!p->flags.precision && !nb))
		len = p->flags.precision;
	if (prefix)
		len += 2;
	if (p->flags.zero_padding && len < p->flags.width)
		len = p->flags.width;
	if (!p->flags.left_justify && p->flags.width)
		print_padd(p, len);
	if (prefix)
	{
		write(1, prefix, 2);
		ft_puthexnb_n(nb, len - 2, p->spec);
	}
	else
		ft_puthexnb_n(nb, len, p->spec);
	if (p->flags.left_justify && p->flags.width)
		print_padd(p, len);
	p->len += len;
}

void	ft_print_ptr(t_printf *p, va_list args)
{
	unsigned long long	addr;
	int					len;

	addr = (unsigned long long)va_arg(args, unsigned long long);
	len = get_hexnb_len(addr);
	if (len < p->flags.precision || (!p->flags.precision && !addr))
		len = p->flags.precision;
	len += 2;
	if (p->flags.zero_padding && len < p->flags.width)
		len = p->flags.width;
	if (!p->flags.left_justify && p->flags.width)
		print_padd(p, len);
	write(1, "0x", 2);
	ft_puthexnb_n(addr, len - 2, p->spec);
	if (p->flags.left_justify && p->flags.width)
		print_padd(p, len);
	p->len += len;
}
