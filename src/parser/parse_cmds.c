/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:20:27 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:45:36 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Mark off the start and end of a simple command.
*/
t_token	*cmd_delimit(t_token *head, t_token **start, t_token **end)
{
	*start = head;
	while (*start && ((*start)->type[0] == CONTROL || (*start)->type[0] == CMD))
		*start = (*start)->next;
	*end = *start;
	while (*end && ((*end)->type[0] == TKN_WORD || (*end)->type[0] == REDIR))
		*end = (*end)->next;
	return (*start);
}

t_token	*create_simple_command(t_token *start, t_token *end)
{
	t_token	*simple_command;

	init_token(&simple_command, "cmd", 3, CMD);
	if (!simple_command)
		return (NULL);
	simple_command->cmd = start;
	while (start->next != end)
		start = start->next;
	start->next = NULL;
	return (simple_command);
}

/*
	Extract simple commands from the token list.
*/
int	simple_command(t_lexer *lexer)
{
	t_token	*start;
	t_token	*end;
	t_token	*simple_command;

	while (cmd_delimit(lexer->head, &start, &end))
	{
		simple_command = create_simple_command(start, end);
		if (!simple_command)
			return (0);
		tkn_dlstinsert_before(lexer, start, simple_command);
		simple_command->next = end;
		end->prev = simple_command;
	}
	return (1);
}
