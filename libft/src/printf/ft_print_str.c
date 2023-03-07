/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:50:08 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:09:53 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(t_printf *p, va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (p->flags.precision != -1 && len > p->flags.precision)
		len = p->flags.precision;
	if (!p->flags.left_justify && p->flags.width > 0)
		print_padd(p, len);
	write(1, str, len);
	p->len += len;
	if (p->flags.left_justify && p->flags.width > 0)
		print_padd(p, len);
}
