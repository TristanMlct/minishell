/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:30 by tmilcent          #+#    #+#             */
/*   Updated: 2023/01/22 19:03:02 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

enum e_node_type
{
	UNKNOWN = 0,
	AND = 10,
	OR = 20,
	PIPE = 30,
	REDIRECT_INPUT = 40,
	REDIRECT_2_INPUT = 41,
	REDIRECT_OUTPUT = 42,
	REDIRECT_2_OUTPUT = 43,
	COMMAND = 50
};

typedef struct s_node
{
	enum e_node_type	type;
	char				*arg;
	struct s_node		**left;
	struct s_node		**right;
}	t_node;

/*
	node_manipulation.c
*/
t_node	*create_node();
void	print_node(t_node node);

/*
	parsing.c
*/
int		count_unescaped_singlequote(char *line);
int		count_unescaped_doublequote(char *line);
char	*sanitize_line(char *line);
t_node	**parse_line(char *line);

#endif