/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:19:54 by mhug              #+#    #+#             */
/*   Updated: 2023/03/01 19:28:12 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	temporary function to print errors
*/
void	print_error(int err, t_lexer *lexer)
{
	char	*str;

	if (err == ERR_MALLOC)
		ft_printf("minishell: Error allocating memory.\n");
	else if (err == ERR_SYNTAX)
	{
		if (lexer->unexpected->type[2] == TKN_NEWLINE)
			str = "newline";
		else
			str = lexer->unexpected->str;
		ft_printf("minishell: syntax error near unexpected token `%s'\n", str);
	}
	else if (err == ERR_NOT_IMPLEMENTED)
	{
		ft_printf("minishell: token `%s' not implemented yet.\n",
			lexer->tail->str);
	}
	else if (err == ERR_STATES)
	{
		ft_printf("minishell: state %s unclosed.\n",
			state_to_display(ft_stack_peek(lexer->states)));
	}
}

int	init_lexer(t_lexer **lexer)
{
	*lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (!*lexer)
		return (0);
	(*lexer)->head = NULL;
	(*lexer)->tail = NULL;
	(*lexer)->unexpected = NULL;
	(*lexer)->is_basic = TRUE;
	ft_stack_init(&(*lexer)->states);
	ft_stack_push(&(*lexer)->states, S_START);
	if (!(*lexer)->states)
		return (0);
	return (1);
}

void	clear_lexer(t_lexer **lexer)
{
	if (!lexer || !*lexer)
		return ;
	tkn_dlstclear(*lexer);
	ft_stack_clear(&(*lexer)->states);
	ft_memdel((void **)lexer);
}

int	all_states_are_closed(t_lexer *lexer)
{
	if (ft_stack_peek(lexer->states) != S_START
		|| (lexer->tail && lexer->tail->type[2] != TKN_NEWLINE))
		return (0);
	return (1);
}
