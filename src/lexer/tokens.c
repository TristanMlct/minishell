/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:20:37 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:44:31 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_token(t_token **token, char *str, int len, int type)
{
	*token = (t_token *)malloc(sizeof(t_token));
	if (!*token)
		return (0);
	(*token)->str = ft_strndup(str, len);
	if (!(*token)->str)
		return (0);
	(*token)->len = len;
	(*token)->type[0] = type;
	(*token)->type[1] = TKN_NULL;
	(*token)->type[2] = TKN_NULL;
	(*token)->cmd = NULL;
	(*token)->prev = NULL;
	(*token)->next = NULL;
	return (1);
}

int	init_op_token(t_token **token, t_op_types *op_type)
{
	if (!init_token(token, op_type->str, op_type->len, op_type->type[0]))
		return (0);
	ft_memcpy((*token)->type, op_type->type, sizeof(op_type->type));
	return (1);
}

/*
	Returns the next blank token.
	(whitespaces unless because newline is an operator token in its own right.)
*/
t_token	*get_blank_token(char *str, int i)
{
	t_token		*token;
	int			len;

	len = 0;
	while (str[i + len] && ft_isblank(str[i + len]))
		++len;
	if (!init_token(&token, str + i, len, TKN_BLANK))
		return (NULL);
	return (token);
}

/*
	Returns the next (control or redirection) operator token.
	The length of the operator is between 1 and 3 characters.
	So we need to check the lenght of the remaining string,
	end next check if we have a match for the operator.
	(obviously, we check for the longest operator first)
*/
t_token	*get_op_token(t_lexer *lexer, char *str, int i, t_op_types *op_types)
{
	t_token			*token;
	t_op_types		*op_type;
	int				len_to_cmp;

	(void)lexer;
	len_to_cmp = ft_min(ft_strlen(str + i), 3);
	while (len_to_cmp > 0)
	{
		op_type = get_op_type(str + i, len_to_cmp, op_types);
		if (op_type)
		{
			if (!init_op_token(&token, op_type))
				return (NULL);
			break ;
		}
		--len_to_cmp;
	}
	return (token);
}

t_token	*get_word_token(t_lexer *lexer, char *str, int i)
{
	t_token		*token;
	int			len;

	len = 0;
	while (str[i + len] && is_word_token(lexer, str[i + len]))
	{
		if (str[i + len] == '\\' && ft_stack_peek(lexer->states) != S_QUOTE)
			len += 2;
		else if (str[i + len] == '\'' || str[i + len] == '"')
			len += update_quote_state(lexer, str, i + len);
		else
			++len;
	}
	if (!init_token(&token, str + i, len, TKN_WORD))
		return (NULL);
	return (token);
}
