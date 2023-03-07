/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:28:48 by mhug              #+#    #+#             */
/*   Updated: 2023/03/07 13:08:47 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_params	t_params;

# include "enums.h"
# include "env.h"
# include "lexer.h"
# include "parser.h"

# define PROMPT "minishell$ "

# define TRUE 1
# define FALSE 0

struct s_params
{
	char		*pgm;
	t_list		*env;
	t_op_types	*op_types;
	char		*input;
	int			exit_code;
};

/* str_utils.c */
char	**ft_split_first(char *str, char c);

/* params_utils.c */
void	malloc_error(t_params *p);
int		init_params(t_params **params, char **envp);
void	clear_params(t_params **params);

#endif
