/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:47 by mhug              #+#    #+#             */
/*   Updated: 2023/03/04 14:17:58 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_next_token(t_lexer *lexer, char *str, int *i, t_op_types *op_types)
{
	t_token	*token;

	token = NULL;
	if (is_last_newline_escaped(lexer, str, *i))
	{
		*i += 2;
		return (1);
	}
	if (is_metacharacter(str[*i]))
	{
		if (ft_isblank(str[*i]))
			token = get_blank_token(str, *i);
		else
			token = get_op_token(lexer, str, *i, op_types);
	}
	else
		token = get_word_token(lexer, str, *i);
	if (!token)
		return (0);
	*i += token->len;
	tkn_dlstadd_back(lexer, token);
	return (1);
}

/*
	Reading the input and creating the lexer.
*/
t_lexer	*get_lexer(char *str, t_op_types *op_types, int *err)
{
	char	*tmp;
	t_lexer	*lexer;
	int		i;

	lexer = NULL;
	tmp = ft_strcatdup(str, "\n", 0, 0);
	if (!tmp || !init_lexer(&lexer))
		*err = ERR_MALLOC;
	i = 0;
	while (*err == 0 && tmp[i])
	{
		if (!add_next_token(lexer, tmp, &i, op_types))
			*err = ERR_MALLOC;
		update_token_type(lexer, *err);
		check_syntax(lexer, err);
		update_state(lexer, *err);
	}
	if (*err == 0 && !all_states_are_closed(lexer))
		*err = ERR_STATES;
	return (ft_strdel(&tmp), lexer);
}
