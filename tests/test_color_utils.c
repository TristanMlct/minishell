/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_color_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:12:04 by tmilcent          #+#    #+#             */
/*   Updated: 2023/01/18 21:17:34 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_parsing.h"

void	red(void)
{
	printf("\033[0;31m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	reset_color(void)
{
	printf("\033[0m");
}
