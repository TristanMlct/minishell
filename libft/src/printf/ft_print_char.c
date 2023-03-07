/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:38:17 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:09:11 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_invalid_spec(t_printf *p, va_list args)
{
	char	c;

	(void)args;
	c = p->spec;
	if (!p->flags.left_justify && p->flags.width > 0)
		print_padd(p, 1);
	write(1, &c, 1);
	++(p->len);
	if (p->flags.left_justify && p->flags.width > 0)
		print_padd(p, 1);
}

void	ft_print_char(t_printf *p, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	if (!p->flags.left_justify && p->flags.width > 0)
		print_padd(p, 1);
	write(1, &c, 1);
	++(p->len);
	if (p->flags.left_justify && p->flags.width > 0)
		print_padd(p, 1);
}
