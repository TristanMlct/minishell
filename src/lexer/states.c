/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:19:12 by mhug              #+#    #+#             */
/*   Updated: 2023/03/01 18:33:05 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_quote_state(t_lexer *lexer, char *str, int i)
{
	t_state	last;

	if (!is_quoted(lexer))
	{
		if (str[i] == '\'' && i != 0 && str[i - 1] == '$')
			ft_stack_push(&(lexer->states), S_QUOTE_ANSI_C);
		else if (str[i] == '\'')
			ft_stack_push(&(lexer->states), S_QUOTE);
		else if (str[i] == '\"')
			ft_stack_push(&(lexer->states), S_DQUOTE);
	}
	else
	{
		last = ft_stack_peek(lexer->states);
		if ((last == S_QUOTE_ANSI_C && str[i] == '\'')
			|| (last == S_QUOTE && str[i] == '\'')
			|| (last == S_DQUOTE && str[i] == '\"'))
			ft_stack_pop(&(lexer->states));
	}
	return (1);
}

void	end_cmd_list(t_lexer *lexer, int pipes, int and_or)
{
	t_state	last;

	last = ft_stack_peek(lexer->states);
	if (pipes)
	{
		while (last == S_PIPE || last == S_ERRPIPE)
		{
			ft_stack_pop(&(lexer->states));
			last = ft_stack_peek(lexer->states);
		}
	}
	if (and_or)
	{
		while (last == S_CMDAND || last == S_CMDOR)
		{
			ft_stack_pop(&(lexer->states));
			last = ft_stack_peek(lexer->states);
		}
	}
}

void	update_control_state(t_lexer *lexer, t_token *token)
{
	if (token->type[1] == AND_OR)
	{
		end_cmd_list(lexer, 1, 0);
		if (token->type[2] == TKN_DAMP)
			ft_stack_push(&(lexer->states), S_CMDAND);
		else if (token->type[2] == TKN_DPIPE)
			ft_stack_push(&(lexer->states), S_CMDOR);
	}
	else if (token->type[1] == CMD_END
		&& prev_relevant_token(token)->type[1] != AND_OR)
		end_cmd_list(lexer, 1, 1);
	else if (token->type[2] == TKN_LPAREN)
		ft_stack_push(&(lexer->states), S_SUBSH);
	else if (token->type[2] == TKN_RPAREN)
	{
		end_cmd_list(lexer, 1, 1);
		if (ft_stack_peek(lexer->states) == S_SUBSH)
			ft_stack_pop(&(lexer->states));
	}
	else if (token->type[2] == TKN_PIPE)
		ft_stack_push(&(lexer->states), S_PIPE);
	else if (token->type[2] == TKN_PIPEAMP)
		ft_stack_push(&(lexer->states), S_ERRPIPE);
}

void	update_state(t_lexer *lexer, int error)
{
	t_token	*last;

	if (error)
		return ;
	last = lexer->tail;
	if (!last)
		return ;
	if (last->type[0] == CONTROL)
		return (update_control_state(lexer, last));
}
