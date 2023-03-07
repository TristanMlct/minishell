/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:44 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:44:36 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_metacharacter(char c)
{
	return (ft_isblank(c) || c == '\n' || c == '|' || c == '&' || c == ';'
		|| c == '<' || c == '>' || c == '(' || c == ')');
}

/*
	Is defined as a word token if:
	- it's not a metacharacter.
	- or it's an escaped metacharacter (quoted or with backslash).
*/
int	is_word_token(t_lexer *lexer, char c)
{
	if (is_quoted(lexer) || !is_metacharacter(c))
		return (1);
	return (0);
}

int	is_last_newline_escaped(t_lexer *lexer, char *str, int i)
{
	if (!is_quoted(lexer) && str[i] == '\\' && str[i + 1] == '\n')
		return (1);
	return (0);
}

void	free_token(t_token **token)
{
	if (token != NULL)
	{
		ft_strdel(&(*token)->str);
		ft_memdel((void **)token);
	}
}

t_token	*prev_relevant_token(t_token *token)
{
	while (token)
	{
		token = token->prev;
		if (!token || token->type[0] != TKN_BLANK)
			break ;
	}
	return (token);
}
