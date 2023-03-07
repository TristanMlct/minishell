/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxe_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:19:41 by mhug              #+#    #+#             */
/*   Updated: 2023/03/02 10:08:28 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Note : 
	Command substitution ('<(list)' and '>(list)') is not supported.
*/
void	check_braces_syntax(t_lexer *lexer, t_token *token, t_token *prev)
{
	if (token->type[2] == TKN_LPAREN)
	{
		if (prev
			&& (prev->type[0] == REDIR
				|| prev->type[0] == TKN_WORD
				|| prev->type[2] == TKN_RPAREN))
				lexer->unexpected = token;
	}
	else if (token->type[2] == TKN_RPAREN)
	{
		if (!prev || (prev->type[1] == AND_OR || prev->type[1] == PIPE)
			|| (prev->type[2] == TKN_LPAREN && !in_function(lexer))
			|| !in_subsh(lexer->states))
				lexer->unexpected = token;
	}
}

void	check_newline_syntax(t_lexer *lexer, t_token *token, t_token *prev)
{
	if (prev && prev->type[0] == REDIR)
		lexer->unexpected = token;
}

/*
	Note :
		group command with braces ('{ list; }') is not supported.
*/
int	follows_gp_cmd(t_token *token)
{
	if (last_control_op_is(token, TKN_RPAREN, 2)
		|| last_control_op_is(token, TKN_RBRACE, 2))
		return (1);
	return (0);
}
