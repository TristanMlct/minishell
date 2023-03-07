/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_displays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:32:20 by mhug              #+#    #+#             */
/*   Updated: 2023/03/01 17:44:08 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*token_type(t_tkn_type type)
{
	if (type == TKN_WORD)
		return ("TKN_WORD");
	else if (type == TKN_AMP)
		return ("TKN_AMP");
	else if (type == TKN_DAMP)
		return ("TKN_DAMP");
	else if (type == TKN_PIPE)
		return ("TKN_PIPE");
	else if (type == TKN_DPIPE)
		return ("TKN_DPIPE");
	else if (type == TKN_SEMI)
		return ("TKN_SEMI");
	else if (type == TKN_DSEMI)
		return ("TKN_DSEMI");
	else if (type == TKN_SEMIAMP)
		return ("TKN_SEMIAMP");
	else if (type == TKN_DSEMIAMP)
		return ("TKN_DSEMIAMP");
	else if (type == TKN_GREAT)
		return ("TKN_GREAT");
	else if (type == TKN_DGREAT)
		return ("TKN_DGREAT");
	else if (type == TKN_LESSGREAT)
		return ("TKN_LESSGREAT");
	else if (type == TKN_LESS)
		return ("TKN_LESS");
	else if (type == TKN_DLESS)
		return ("TKN_DLESS");
	else if (type == TKN_TLESS)
		return ("TKN_TLESS");
	else if (type == TKN_DLESSDASH)
		return ("TKN_DLESSDASH");
	else if (type == TKN_LESSAMP)
		return ("TKN_LESSAMP");
	else if (type == TKN_GREATAMP)
		return ("TKN_GREATAMP");
	else if (type == TKN_AMPGREAT)
		return ("TKN_AMPGREAT");
	else if (type == TKN_AMPDGREAT)
		return ("TKN_AMPDGREAT");
	else if (type == TKN_PIPEAMP)
		return ("TKN_PIPEAMP");
	else if (type == TKN_GREATPIPE)
		return ("TKN_GREATPIPE");
	else if (type == TKN_LPAREN)
		return ("TKN_LPAREN");
	else if (type == TKN_RPAREN)
		return ("TKN_RPAREN");
	else if (type == TKN_NEWLINE)
		return ("TKN_NEWLINE");
	else if (type == TKN_BLANK)
		return ("TKN_BLANK");
	else if (type == REDIR)
		return ("REDIR");
	else if (type == CMD)
		return ("CMD");
	else if (type == CONTROL)
		return ("CONTROL");
	else if (type == GP_CMD)
		return ("GP_CMD");
	else if (type == CMD_END)
		return ("CMD_END");
	else if (type == AND_OR)
		return ("AND_OR");
	else if (type == IO_FILE)
		return ("IO_FILE");
	else if (type == IO_HERE)
		return ("IO_HERE");
	else if (type == IO_DUP)
		return ("IO_DUP");
	else if (type == IO_CLOSE)
		return ("IO_CLOSE");
	else if (type == PIPE)
		return ("PIPE");
	else if (type == IO_NUMBER)
		return ("IO_NUMBER");
	else if (type == FILENAME)
		return ("FILENAME");
	else if (type == HERE_END)
		return ("HERE_END");
	else if (type == ASSIGN_WORD)
		return ("ASSIGN_WORD");
	else if (type == CMD_NAME)
		return ("CMD_NAME");
	else if (type == CMD_ARG)
		return ("CMD_ARG");
	else if (type == CMD)
		return ("CMD");
	else
		return ("TKN_NULL");
}

/*
	For debugging purposes.
	Should not be normed.
*/
void	display_op_types(t_op_types *t)
{
	int		i;

	i = 0;
	while (t[i].type[0] != 0)
	{
		if (i == 0)
			ft_printf("Control operators: (to interpret)\n");
		else if (i == 6)
			ft_printf("Control operators: (not to interpret)\n");
		else if (i == 12)
			ft_printf("Redirection operators: (to interpret)\n");
		else if (i == 16)
			ft_printf("Redirection operators: (not to interpret)\n");
		if (t[i].type[2] == TKN_NEWLINE)
			ft_printf("[%-2d] \"newline\"\n", i);
		else
			ft_printf("[%-2d] \"%s\"\n", i, t[i].str);
		++i;
	}
}

char	*token_to_display(t_token *token)
{
	if (token->type[0] == TKN_BLANK)
		return ("[]");
	else if (token->type[2] == TKN_NEWLINE)
		return ("[newline]");
	else
		return (token->str);
}

void	display_tokens(t_lexer *lexer)
{
	t_token	*ptr;
	char	*str;

	ptr = lexer->head;
	if (ptr == NULL)
		ft_printf("Empty list\n");
	while (ptr != NULL)
	{
		str = token_to_display(ptr);
		if (ptr == lexer->head && ptr == lexer->tail)
			ft_printf("[h/t]%s\n", str);
		else if (ptr == lexer->head)
			ft_printf("[h]%s-", str);
		else if (ptr == lexer->tail)
			ft_printf("[t]%s\n", str);
		else
			ft_printf("%s-", str);
		ptr = ptr->next;
	}
}

void	recursive_token_display(t_lexer *lexer, t_token *token)
{
	t_token	*ptr;
	char	*str;

	ptr = token;
	while (ptr != NULL)
	{
		str = token_to_display(ptr);
		if (ptr == lexer->head && ptr == lexer->tail)
			ft_printf("[h/t]%s\n", str);
		else if (ptr == lexer->head)
		{
			if (ptr->type[0] == CMD || ptr->type[0] == SUBSH)
				ft_printf("[h]");
			else
				ft_printf("[h]%s", str);
		}
		else if (ptr == lexer->tail)
			ft_printf("[t]%s\n", str);
		else if (ptr->next == NULL
			&& ptr->type[0] != CMD && ptr->type[0] != SUBSH)
			ft_printf("%s ", str);
		else
		{
			if (ptr->type[0] != CMD && ptr->type[0] != SUBSH)
				ft_printf("%s ", str);
		}
		if (ptr->type[0] == CMD || ptr->type[0] == SUBSH)
		{
			if (ptr->type[0] == CMD)
				ft_printf("\033[33m");
			else
				ft_printf("\033[34m[ \033[0m");
			recursive_token_display(lexer, ptr->cmd);
			if (ptr->type[0] == CMD)
				ft_printf("\033[0m");
			else
				ft_printf("\033[34m] \033[0m");
		}
		ptr = ptr->next;
	}
}

char	*state_to_display(t_state state)
{
	if (state == S_START)
		return ("S_START");
	else if (state == S_QUOTE)
		return ("S_QUOTE");
	else if (state == S_QUOTE_ANSI_C)
		return ("S_QUOTE_ANSI_C");
	else if (state == S_DQUOTE)
		return ("S_DQUOTE");
	else if (state == S_BQUOTE)
		return ("S_BQUOTE");
	else if (state == S_PIPE)
		return ("S_PIPE");
	else if (state == S_ERRPIPE)
		return ("S_ERRPIPE");
	else if (state == S_CMDOR)
		return ("S_CMDOR");
	else if (state == S_CMDAND)
		return ("S_CMDAND");
	else if (state == S_SUBSH)
		return ("S_SUBSH");
	else if (state == S_MATH)
		return ("S_MATH");
	else if (state == S_CURSH)
		return ("S_CURSH");
	else if (state == S_CMDSUBST)
		return ("S_CMDSUBST");
	else if (state == S_MATHSUBST)
		return ("S_MATHSUBST");
	else if (state == S_MATHSUBST_SQ)
		return ("S_MATHSUBST_SQ");
	else if (state == S_BRACEPARAM)
		return ("S_BRACEPARAM");
	else
		return ("UNKNOWN");
}

void	display_stack(t_stack *stack)
{
	t_stack	*elem;

	elem = stack;
	while (elem)
	{
		ft_printf("%s ", state_to_display(elem->state));
		elem = elem->next;
	}
	ft_printf("\n");
}

void	debug_syntax(t_state state, t_token *token, t_token *prev_token)
{
	if (token->type[2] == TKN_NEWLINE || token->type[2] == TKN_BLANK)
		return ;
	ft_printf("token \"%s\" [%s][%s][%s]\n",
		token->str,
		token_type(token->type[0]),
		token_type(token->type[1]),
		token_type(token->type[2]));
	if (prev_token)
		ft_printf("prev_token \"%s\" [%s][%s][%s]\n",
			prev_token->str,
			token_type(prev_token->type[0]),
			token_type(prev_token->type[1]),
			token_type(prev_token->type[2]));
	else
		ft_printf("prev_token NULL\n");
	ft_printf("state -> %s\n\n", state_to_display(state));
}
