/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:20:13 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:45:13 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_stack_init(t_stack **stack)
{
	*stack = NULL;
}

int	is_quoted(t_lexer *lexer)
{
	t_state	last;

	last = ft_stack_peek(lexer->states);
	return (last == S_QUOTE || last == S_DQUOTE || last == S_QUOTE_ANSI_C);
}
