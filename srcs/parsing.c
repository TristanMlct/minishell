/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:06:37 by tmilcent          #+#    #+#             */
/*   Updated: 2023/02/16 10:49:52 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Parsing :
		- Transform line in tokens and put them in a linked list
		- Analyse tokens
		- Transform tokens in a tree
		- Check if tree is valid
		- Execute tree
*/
/*
	Tokens :
		- WORD : a word, between quotes or not
		- PIPE : a |
		- REDIRECT : a >, <, >> or <<
		- AND : a &&
		- OR : a ||
		- PARENTHESIS : a ( or )
*/

/*
	parsing :
		- Call tokenize to transform line in tokens
		- Call check_tokens to check if tokens are valid
	Return :
		- NULL if an error occured
		- A linked list of tokens if everything is ok
*/
t_token	*parsing(char *line)
{
	t_token	*tokens;

	tokens = NULL;
	tokens = tokenize(line);
	if (tokens == NULL)
		return (NULL);
	if (analyse_tokens(tokens) == 0)
		return (NULL);
	return (tokens);
}

/*
	tokenize :
		- Transform line into tokens
		- Put tokens in a linked list
	Return :
		- NULL if an error occured
		- A linked list of tokens if everything is ok
*/
t_token *tokenize(char *line)
{
	t_token	*tokens;
	int		i;
	int		in_word;
	char	quote_type;

	i = -1;
	in_word = 0;
	tokens = NULL;
	while (line[++i])
	{
		if (in_word == 1 && !ft_isspace(line[i]) && !ft_isoperator(line[i]))
		{
			if (add_char_to_last_token(tokens, line[i]) == 0)
			{
				free_tokens(tokens);
				return (NULL);
			}
		}
		else if (line[i] == '"' || line[i] == '\'')
		{
			quote_type = line[i];
			in_word = 0;
			if (add_token(&tokens, line[i]) == 0)
			{
				free_tokens(tokens);
				return (NULL);
			}
			i++;
			while (line[i] != quote_type && line[i])
			{
				if (add_char_to_last_token(tokens, line[i]) == 0)
				{
					free_tokens(tokens);
					return (NULL);
				}
				i++;
			}
			if (!line[i] || add_char_to_last_token(tokens, line[i]) == 0)
			{
				free_tokens(tokens);
				return (NULL);
			}
		}
		else if (in_word == 0 && !ft_isspace(line[i]) && !ft_isoperator(line[i]))
		{
			in_word = 1;
			if (add_token(&tokens, line[i]) == 0)
			{
				free_tokens(tokens);
				return (NULL);
			}
		}
		else if (ft_isoperator(line[i]) == 1 && line[i] == line[i + 1])
		{
			in_word = 0;
			if (add_token(&tokens, line[i]) == 0)
			{
				free_tokens(tokens);
				return (NULL);
			}
			i++;
			if (add_char_to_last_token(tokens, line[i]) == 0)
			{
				free_tokens(tokens);
				return (NULL);
			}
		}
		else if (ft_isoperator(line[i]) == 1)
		{
			in_word = 0;
			if (add_token(&tokens, line[i]) == 0)
			{
				free_tokens(tokens);
				return (NULL);
			}
		}
		else if (in_word == 1 && (ft_isspace(line[i]) == 1 || ft_isoperator(line[i]) == 1))
			in_word = 0;
	}
	return (tokens);
}

/*
	ft_isoperator :
		- Check if a char is an operator
	Return :
		- 1 if it is an operator
		- 0 if it is not an operator
*/
int ft_isoperator(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == '&' || c == '(' || c == ')')
		return (1);
	return (0);
}

/*
	ft_isspace :
		- Check if a char is a space
	Return :
		- 1 if it is a space
		- 0 if it is not a space
*/
int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

/*
	analyse_tokens :
		- set type of each token
	Return :
		- 0 if an error occured
		- 1 if everything is ok
*/
int analyse_tokens(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == -1)
		{
			if (tmp->value[0] == '|' && tmp->value[1] == '|')
				tmp->type = OR;
			else if (tmp->value[0] == '|')
				tmp->type = PIPE;
			else if (tmp->value[0] == '>' && tmp->value[1] == '>')
				tmp->type = REDIRECT;
			else if (tmp->value[0] == '<' && tmp->value[1] == '<')
				tmp->type = REDIRECT;
			else if (tmp->value[0] == '>' && tmp->value[1] == '\0')
				tmp->type = REDIRECT;
			else if (tmp->value[0] == '<' && tmp->value[1] == '\0')
				tmp->type = REDIRECT;
			else if (tmp->value[0] == '&' && tmp->value[1] == '&')
				tmp->type = AND;
			else if (tmp->value[0] == '(')
				tmp->type = PARENTHESIS;
			else if (tmp->value[0] == ')')
				tmp->type = PARENTHESIS;
			else
				tmp->type = WORD;
		}
		tmp = tmp->next;
	}
	return (1);
}

void tester_tokenize(char *line)
{
	t_token *tokens;
	tokens = NULL;
	tokens = tokenize(line);
	printf("line : %s\n", line);
	display_tokens(tokens);
	printf("\n");
	free_tokens(tokens);
}

void test_tokenize()
{
	// tester_tokenize("ls -l | cat -e > file");
	// tester_tokenize("cat | cat | ls ");
	// tester_tokenize("cat|cat|ls>file");
	// tester_tokenize("(echo a && echo b) || (echo c && echo d)");
	// tester_tokenize("(echo a && echo b) >> file");
	tester_tokenize("echo \"a b c\" > file");
	tester_tokenize("echo \"a b c > file");
}

void tester_analyse_tokens(char *line)
{
	t_token *tokens;
	tokens = NULL;
	tokens = tokenize(line);
	analyse_tokens(tokens);
	printf("line : %s\n", line);
	display_tokens(tokens);
	printf("\n");
	free_tokens(tokens);
}

void test_analyse_tokens()
{
	tester_analyse_tokens("ls -l | cat -e > file");
	tester_analyse_tokens("cat | cat | ls ");
	tester_analyse_tokens("cat|cat|ls>file");
	tester_analyse_tokens("(echo a && echo b) || (echo c && echo d)");
	tester_analyse_tokens("(echo a && echo b) >> file");
	tester_analyse_tokens("ec'ho' \"a b c\" > file");
	tester_analyse_tokens("ec'ho' \"a b c > file");
}

int main()
{
	test_analyse_tokens();
	return (0);
}