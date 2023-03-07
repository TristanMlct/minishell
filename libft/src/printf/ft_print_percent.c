/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:42:37 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:09:46 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_printf *p, va_list args)
{
	(void)args;
	if (!p->flags.left_justify && p->flags.width > 0)
		print_padd(p, 1);
	write(1, "%", 1);
	++(p->len);
	if (p->flags.left_justify && p->flags.width > 0)
		print_padd(p, 1);
}
