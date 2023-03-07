/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_gp_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:20:41 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:45:39 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*gp_cmd_delimit(t_token *tail, t_token **start, t_token **end)
{
	*start = tail;
	while (*start && (*start)->type[2] != TKN_LPAREN)
		*start = (*start)->prev;
	*end = *start;
	while (*end && (*end)->type[2] != TKN_RPAREN)
		*end = (*end)->next;
	return (*start);
}

t_token	*create_group_command(t_token *start, t_token *end)
{
	t_token	*group_command;

	init_token(&group_command, "subsh", 5, SUBSH);
	if (!group_command)
		return (NULL);
	group_command->cmd = start;
	while (start->next != end)
		start = start->next;
	start->next = NULL;
	return (group_command);
}

void	test(t_token *group_command)
{
	t_token	*to_del;
	t_token	*tmp;

	tmp = group_command->cmd->next;
	to_del = group_command->cmd;
	free_token(&to_del);
	group_command->cmd = tmp;
}

int	group_command(t_lexer *lexer)
{
	t_token	*start;
	t_token	*end;
	t_token	*group_command;

	while (gp_cmd_delimit(lexer->tail, &start, &end))
	{
		group_command = create_group_command(start, end);
		if (!group_command)
			return (0);
		tkn_dlstinsert_before(lexer, start, group_command);
		group_command->next = end;
		end->prev = group_command;
		tkn_dlstdelone(lexer, end);
		test(group_command);
	}
	return (1);
}
