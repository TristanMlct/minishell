/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxe_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:22:48 by mhug              #+#    #+#             */
/*   Updated: 2023/03/02 10:08:17 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_subsh(t_stack *states)
{
	t_state	state;

	if (!states)
		return (0);
	state = ft_stack_peek(states);
	while (states && (state == S_CMDAND || state == S_CMDOR
			|| state == S_PIPE || state == S_ERRPIPE))
	{
		states = states->next;
		if (states)
			state = ft_stack_peek(states);
	}
	if (states && ft_stack_peek(states) == S_SUBSH)
		return (1);
	return (0);
}

/*
	Note : 
	Case command ('case word in .. esac') is not supported.
*/
int	in_case_command(t_lexer *lexer)
{
	if (lexer->is_basic)
		return (0);
	return (1);
}

/*
	Note :
	functions ('fname () compound-cmd [redir]' 
		and 'function fname [()] compound-command [redir]') are not supported.
*/
int	in_function(t_lexer *lexer)
{
	if (lexer->is_basic)
		return (0);
	return (1);
}

int	is_first_tkn_word_in_cmd(t_token *token)
{
	t_token	*prev;

	prev = prev_relevant_token(token);
	if (!prev)
		return (1);
	return (prev->type[0] != TKN_WORD && prev->type[0] != REDIR);
}

int	last_control_op_is(t_token *token, t_tkn_type type, int index)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type[0] == CONTROL)
			return (tmp->type[index] == type);
		tmp = tmp->prev;
	}
	return (0);
}
