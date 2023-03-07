/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils_dlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:55:53 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:44:39 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Delete one element from the list.
*/
void	tkn_dlstdelone(t_lexer *lexer, t_token *token)
{
	if (!lexer->head || !token)
		return ;
	if (token->prev)
		token->prev->next = token->next;
	else
		lexer->head = token->next;
	if (token->next)
		token->next->prev = token->prev;
	else
		lexer->tail = token->prev;
	free_token(&token);
}

/*void	tkn_dlstadd_front(t_lexer *lexer, t_token *new)
{
	if (!lexer->head)
	{
		lexer->head = new;
		lexer->tail = new;
	}
	else
	{
		new->next = lexer->head;
		lexer->head->prev = new;
		lexer->head = new;
	}
}*/

/*
	Inserts the element at the end of the list.
*/
void	tkn_dlstadd_back(t_lexer *lexer, t_token *new)
{
	if (!lexer->head)
	{
		lexer->head = new;
		lexer->tail = new;
	}
	else
	{
		lexer->tail->next = new;
		new->prev = lexer->tail;
		lexer->tail = new;
	}
}

/*
	Insert token after another specific token.
*/
/*void	tkn_dlstinsert_after(t_lexer *lexer, t_token *token, t_token *new)
{
	if (!lexer->head || !token || !new)
		return ;
	new->next = token->next;
	new->prev = token;
	token->next = new;
	if (new->next)
		new->next->prev = new;
	else
		lexer->tail = new;
}*/

/*
	Insert token before another specific token.
*/
void	tkn_dlstinsert_before(t_lexer *lexer, t_token *token, t_token *new)
{
	if (!lexer->head || !token || !new)
		return ;
	new->next = token;
	new->prev = token->prev;
	token->prev = new;
	if (new->prev)
		new->prev->next = new;
	else
		lexer->head = new;
}

void	recursive_del(t_token *token)
{
	t_token	*ptr;
	t_token	*to_del;

	ptr = token;
	while (ptr != NULL)
	{
		to_del = ptr;
		if (to_del->cmd)
			recursive_del(to_del->cmd);
		ptr = ptr->next;
		free_token(&to_del);
	}
	token = NULL;
	ptr = NULL;
}

/*
	Remove all elements of the list.
*/
void	tkn_dlstclear(t_lexer *lexer)
{
	t_token	*ptr;
	t_token	*to_del;

	if (!lexer || (!lexer->head && !lexer->tail))
		return ;
	ptr = lexer->head;
	while (ptr != NULL)
	{
		to_del = ptr;
		recursive_del(to_del->cmd);
		ptr = ptr->next;
		tkn_dlstdelone(lexer, to_del);
	}
	lexer->head = NULL;
	lexer->tail = NULL;
}
