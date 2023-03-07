/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:28:26 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:10:14 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padd(t_printf *p, int len)
{
	int	padding;

	padding = p->flags.width - len;
	if (padding < 0)
		return ;
	while (padding--)
	{
		if (!(p->spec == 's') && p->flags.zero_padding)
		{
			write(1, "0", 1);
			++(p->len);
		}
		else
		{
			write(1, " ", 1);
			++(p->len);
		}
	}
}

void	get_specifier(t_printf *p, char c)
{
	p->spec = c;
	if (p->spec == '%')
		p->print_spec = &ft_print_percent;
	else if (p->spec == 'c')
		p->print_spec = &ft_print_char;
	else if (p->spec == 's')
		p->print_spec = &ft_print_str;
	else if (p->spec == 'd' || p->spec == 'i')
		p->print_spec = &ft_print_int;
	else if (p->spec == 'u')
		p->print_spec = &ft_print_uint;
	else if (p->spec == 'x' || p->spec == 'X')
		p->print_spec = &ft_print_hex;
	else if (p->spec == 'p')
		p->print_spec = &ft_print_ptr;
	else
		p->print_spec = &ft_print_invalid_spec;
}
