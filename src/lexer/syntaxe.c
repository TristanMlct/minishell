/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:37 by mhug              #+#    #+#             */
/*   Updated: 2023/03/02 10:09:19 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_control_op_syntax(t_lexer *lexer, t_token *token, t_token *prev)
{
	if (token->type[2] == TKN_NEWLINE)
		check_newline_syntax(lexer, token, prev);
	else if (token->type[1] == SUBSH)
		check_braces_syntax(lexer, token, prev);
	else if (token->type[1] == CASE_END && !in_case_command(lexer))
		lexer->unexpected = token;
	else if (!prev
		|| prev->type[0] == REDIR
		|| (prev->type[0] == CONTROL && prev->type[2] != TKN_RPAREN))
		lexer->unexpected = token;
}

void	check_redir_op_syntax(t_lexer *lexer, t_token *token, t_token *prev)
{
	if (prev && prev->type[0] == REDIR)
		lexer->unexpected = token;
	else if (prev && prev->type[1] == CMD_NAME)
		check_tkn_word_syntax(lexer, prev);
}

void	check_tkn_word_syntax(t_lexer *lexer, t_token *token)
{
	if (token->type[1] == CMD_NAME && follows_gp_cmd(token))
	{
		if (ft_str_isdigit(token->str) && token == lexer->tail)
			return ;
		lexer->unexpected = token;
	}
	else if (is_first_tkn_word_in_cmd(token) && ft_strcmp(token->str, "}") == 0)
		lexer->unexpected = token;
}

void	check_syntax(t_lexer *lexer, int *err)
{
	t_token	*token;
	t_token	*prev;

	if (*err != 0)
		return ;
	token = lexer->tail;
	prev = prev_relevant_token(token);
	if (token->type[0] == CONTROL)
		check_control_op_syntax(lexer, token, prev);
	else if (token->type[0] == REDIR)
		check_redir_op_syntax(lexer, token, prev);
	else if (token->type[0] == TKN_WORD)
		check_tkn_word_syntax(lexer, token);
	if (lexer->unexpected && !*err)
		*err = ERR_SYNTAX;
}
