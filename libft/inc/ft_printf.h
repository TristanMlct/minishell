/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:21:00 by mhug              #+#    #+#             */
/*   Updated: 2022/12/26 11:07:41 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
	int	width;
	int	left_justify;
	int	zero_padding;
	int	sign_prefix;
	int	space_prefix;
	int	base_prefix;
	int	precision;
}				t_flags;

typedef struct s_printf
{
	void	(*print_spec)(struct s_printf *, va_list);
	char	spec;
	int		i;
	int		len;
	t_flags	flags;
}				t_printf;

int		ft_printf(const char *format, ...);

void	get_specifier(t_printf *p, char c);
void	get_flags(t_printf *p, const char *str, va_list args);
void	print_padd(t_printf *p, int len);

void	ft_print_percent(t_printf *p, va_list args);
void	ft_print_char(t_printf *p, va_list args);
void	ft_print_str(t_printf *p, va_list args);
void	ft_print_int(t_printf *p, va_list args);
void	ft_print_uint(t_printf *p, va_list args);
void	ft_print_hex(t_printf *p, va_list args);
void	ft_print_ptr(t_printf *p, va_list args);
void	ft_print_invalid_spec(t_printf *p, va_list args);

#endif
