/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:15:06 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:08:58 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->left_justify = 0;
	flags->zero_padding = 0;
	flags->sign_prefix = 0;
	flags->space_prefix = 0;
	flags->base_prefix = 0;
	flags->precision = -1;
}

int	is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '#' || c == '-'
		|| c == '*' || c == '.' || c == '0' || ft_isdigit(c))
		return (1);
	return (0);
}

void	get_precision(t_printf *p, const char *str, va_list args)
{
	if (p->flags.zero_padding)
		p->flags.zero_padding = 0;
	if (str[++(p->i)] == '*')
	{
		p->flags.precision = va_arg(args, int);
		return ;
	}
	p->flags.precision = 0;
	while (ft_isdigit(str[p->i]))
	{
		p->flags.precision = (p->flags.precision) * 10 + (str[p->i] - '0');
		++(p->i);
	}
	--(p->i);
}

void	get_width(t_printf *p, const char *str, va_list args)
{
	if (str[p->i] == '*')
	{
		p->flags.width = va_arg(args, int);
		if (p->flags.width < 0)
		{
			p->flags.left_justify = 1;
			p->flags.width *= -1;
			++(p->i);
		}
	}
	else
	{
		while (ft_isdigit(str[p->i]))
		{
			p->flags.width = (p->flags.width) * 10 + (str[p->i] - '0');
			++(p->i);
		}
		--(p->i);
	}
}

void	get_flags(t_printf *p, const char *str, va_list args)
{
	init_flags(&(p->flags));
	while (str[++(p->i)] != '\0' && is_flag(str[p->i]))
	{
		if (str[p->i] == ' ')
			p->flags.space_prefix = 1;
		else if (str[p->i] == '+')
			p->flags.sign_prefix = 1;
		else if (str[p->i] == '#')
			p->flags.base_prefix = 1;
		else if (str[p->i] == '-')
		{
			p->flags.left_justify = 1;
			p->flags.zero_padding = 0;
		}
		else if (str[p->i] == '0' && !p->flags.left_justify
			&& !p->flags.width && p->flags.precision == -1)
			p->flags.zero_padding = 1;
		else if (str[p->i] == '.')
			get_precision(p, str, args);
		else if (str[p->i] == '*' || ft_isdigit(str[p->i]))
			get_width(p, str, args);
	}
}
/*
void	check(t_printf *p)
{
	printf("space_prefix = %d\n", p->flags.space_prefix);
	printf("sign_prefix = %d\n", p->flags.sign_prefix);
	printf("base_prefix = %d\n", p->flags.base_prefix);
	printf("zero_padding = %d\n", p->flags.zero_padding);
	printf("precision = %d\n", p->flags.precision);
	printf("left_justify = %d\n", p->flags.left_justify);
	printf("width = %d\n", p->flags.width);
	printf("specifier = %c\n", p->spec);
}
*/
