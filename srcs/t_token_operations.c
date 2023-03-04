/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:08:49 by tmilcent          #+#    #+#             */
/*   Updated: 2023/02/15 16:34:13 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	free_token :
		- Free a token
	Return :
		- Nothing
*/
void	free_token(t_token *token)
{
	if (token->value)
		free(token->value);
	free(token);
}

/*
	free_tokens :
		- Free a linked list of tokens
	Return :
		- Nothing
*/
void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free_token(tmp);
	}
}

/*
	display_token :
		- Display a token
	Return :
		- Nothing
*/
void	display_token(t_token *token)
{
	if (token->type == WORD)
		printf("Token : %s, type : %s\n", token->value, "WORD");
	else if (token->type == PIPE)
		printf("Token : %s, type : %s\n", token->value, "PIPE");
	else if (token->type == REDIRECT)
		printf("Token : %s, type : %s\n", token->value, "REDIRECT");
	else if (token->type == AND)
		printf("Token : %s, type : %s\n", token->value, "AND");
	else if (token->type == OR)
		printf("Token : %s, type : %s\n", token->value, "OR");
	else if (token->type == PARENTHESIS)
		printf("Token : %s, type : %s\n", token->value, "PARENTHESIS");
	else
		printf("Token : %s, type : %s\n", token->value, "UNKNOWN");
}

/*
	display_tokens :
		- Display a linked list of tokens
	Return :
		- Nothing
*/
void	display_tokens(t_token *tokens)
{
	printf("Start of tokens\n");
	while (tokens)
	{
		display_token(tokens);
		tokens = tokens->next;
	}
	printf("End of tokens\n");
}

/*
	count_tokens :
		- Count the number of tokens in a linked list of tokens
	Return :
		- The number of tokens
*/
int	count_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		i++;
		tokens = tokens->next;
	}
	return (i);
}

/*
	find_last_token :
		- Find the last token in a linked list of tokens
	Return :
		- The last token
*/
t_token	*find_last_token(t_token *tokens)
{
	while (tokens->next)
		tokens = tokens->next;
	return (tokens);
}

/*
	add_token :
		- Add a token to a linked list of tokens
		- If the linked list is empty, the token will be the first one
	Return :
		- 0 if an error occured
		- 1 if everything is ok
*/
int	add_token(t_token **tokens, char c)
{
	t_token	*new_token;
	t_token	*last_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (0);
	new_token->value = NULL;
	new_token->value = (char *)malloc(sizeof(char) * 2);
	if (new_token->value == NULL)
		return (0);
	new_token->value[0] = c;
	new_token->value[1] = '\0';
	new_token->type = -1;
	new_token->next = NULL;
	if (!(*tokens))
		*tokens = new_token;
	else
	{
		last_token = find_last_token(*tokens);
		last_token->next = new_token;
	}
	return (1);
}

/*
	add_char_to_last_token :
		- Add a char to the last token
	Return :
		- 0 if an error occured
		- 1 if everything is ok
*/
int	add_char_to_last_token(t_token *tokens, char c)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (tokens->next != NULL)
		tokens = tokens->next;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(tokens->value) + 2));
	if (tmp == NULL)
		return (0);
	while (tokens->value[++i])
		tmp[i] = tokens->value[i];
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(tokens->value);
	tokens->value = tmp;
	return (1);
}
