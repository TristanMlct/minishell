/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:07:06 by tmilcent          #+#    #+#             */
/*   Updated: 2023/02/15 16:38:04 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

enum e_token_type
{
	UNKNOWN = -1,
	WORD = 0,
	PIPE = 1,
	REDIRECT = 2,
	AND = 3,
	OR = 4,
	PARENTHESIS = 5
};

typedef struct s_token
{
	char				*value;
	enum e_token_type	type;
	struct s_token		*next;
}				t_token;

/*
	t_token_operations.c
*/
void	free_token(t_token *token);
void	free_tokens(t_token *tokens);
void	display_token(t_token *token);
void	display_tokens(t_token *tokens);
int		count_tokens(t_token *tokens);
t_token	*find_last_token(t_token *tokens);
int		add_token(t_token **tokens, char c);
int		add_char_to_last_token(t_token *tokens, char c);

/*
	parsing.c
*/
t_token	*parsing(char *line);
t_token	*tokenize(char *line);
int		ft_isoperator(char c);
int		ft_isspace(char c);
int analyse_tokens(t_token *tokens);

#endif