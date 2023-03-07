/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:17:38 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:36:08 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "lexer.h"

/* parse_cmds.c */
t_token	*cmd_delimit(t_token *head, t_token **start, t_token **end);
t_token	*create_simple_command(t_token *start, t_token *end);
int		simple_command(t_lexer *lexer);

/* parse_gp_cmds.c */
t_token	*gp_cmd_delimit(t_token *tail, t_token **start, t_token **end);
t_token	*create_group_command(t_token *start, t_token *end);
int		group_command(t_lexer *lexer);

/* pre_parse.c */
void	remove_blank_tokens(t_lexer *lexer);
int		pre_parse(t_lexer *lexer, int *err);

#endif