/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:27:35 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:10:04 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process(t_printf *p, const char *str, va_list args)
{
	while (str[p->i])
	{
		if (str[p->i] == '%' && str[p->i + 1] != '\0')
		{
			get_flags(p, str, args);
			get_specifier(p, str[(p->i)++]);
			p->print_spec(p, args);
		}
		else
		{
			write(1, &str[p->i], 1);
			++(p->i);
			++(p->len);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_printf	p;

	if (!format || *format == '\0')
		return (0);
	p.i = 0;
	p.len = 0;
	va_start(args, format);
	process(&p, format, args);
	va_end(args);
	return (p.len);
}
