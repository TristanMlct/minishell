/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:18:06 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:45:43 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_blank_tokens(t_lexer *lexer)
{
	t_token	*token;
	t_token	*to_del;

	token = lexer->head;
	while (token != NULL)
	{
		to_del = token;
		token = token->next;
		if (to_del->type[0] == TKN_BLANK)
			tkn_dlstdelone(lexer, to_del);
	}
}

int	pre_parse(t_lexer *lexer, int *err)
{
	remove_blank_tokens(lexer);
	if (!simple_command(lexer) || !group_command(lexer))
		*err = ERR_MALLOC;
	return (*err == 0);
}
