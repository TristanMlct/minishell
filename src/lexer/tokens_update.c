/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:32 by mhug              #+#    #+#             */
/*   Updated: 2023/03/02 09:46:05 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	update_debug(t_token *token) // DEBUG
{
	ft_printf(
		"le token \"%s\" devient un %s\n",
		token->str,
		token_type(token->type[1]));
}*/

int	is_an_assignment_word(t_token *token)
{
	int	i;

	i = 0;
	while (token->str[i])
	{
		if (i != 0 && token->str[i] == '=')
			return (1);
		else if (!(token->str[i] == '_' || ft_isalnum(token->str[i])))
			return (0);
		i++;
	}
	return (0);
}

int	there_is_not_a_cmd_name_in_simple_command(t_token *token)
{
	t_token	*prev;

	prev = prev_relevant_token(token);
	while (prev)
	{
		if (prev->type[0] == CONTROL)
			break ;
		if (prev->type[1] == CMD_NAME)
			return (0);
		prev = prev_relevant_token(prev);
	}
	return (1);
}

/*
	Notes :
		- ADD token type PATHNAME ?
*/
void	update_word_token_type(t_token *token, t_token *prev)
{
	if (prev && prev->type[1] == IO_FILE)
		token->type[1] = FILENAME;
	else if (prev && prev->type[1] == IO_HERE)
		token->type[1] = HERE_END;
	else if (prev && prev->type[1] == IO_DUP)
	{
		if (ft_str_isdigit(token->str))
			token->type[1] = IO_NUMBER;
		else if (ft_strcmp(token->str, "-") == 0)
			prev->type[1] = IO_CLOSE;
		else
			token->type[1] = FILENAME;
	}
	else if (there_is_not_a_cmd_name_in_simple_command(token))
	{
		if (is_an_assignment_word(token))
			token->type[1] = ASSIGN_WORD;
		else
			token->type[1] = CMD_NAME;
	}
	else
		token->type[1] = CMD_ARG;
}

/*
	Notes:
		- First if → handle case if previous is left brace (unquoted)
			- if it's the first word in the simple command → reserved word
		- IO_NUMBER is limited to certain values ?
			-before redirection
				(0-9) if not another files open ?
			-after redirection
				only 0, 1, 2 ? (or another files open ?)
					$ echo test <&3
					  bash: 3: Bad file descriptor
			how and when to determine them ?
*/
void	update_token_type(t_lexer *lexer, int error)
{
	t_token	*token;
	t_token	*prev;

	if (error)
		return ;
	token = lexer->tail;
	prev = prev_relevant_token(token);
	if (token->type[0] == TKN_BLANK || token->type[0] == TKN_NEWLINE)
		return ;
	else if (token->type[0] == REDIR)
	{
		if (token->prev && ft_str_isdigit(token->prev->str))
			token->prev->type[1] = IO_NUMBER;
	}
	else if (token->type[0] == TKN_WORD)
		update_word_token_type(token, prev);
}
