/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:47:49 by mhug              #+#    #+#             */
/*   Updated: 2023/03/07 13:10:54 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// THINK: should we use a hash table instead of an array?

/*
	Fill the array token types with the control operators types.
	0 to 5 must be interpreted by miniShell.
	6 to 11 must not be interpreted by miniShell.
*/
void	fill_control_op_types(t_op_types **op_types)
{
	(*op_types)[0] = (t_op_types){"&&", 2, {CONTROL, AND_OR, TKN_DAMP}};
	(*op_types)[1] = (t_op_types){"|", 1, {CONTROL, PIPE, TKN_PIPE}};
	(*op_types)[2] = (t_op_types){"||", 2, {CONTROL, AND_OR, TKN_DPIPE}};
	(*op_types)[3] = (t_op_types){"(", 1, {CONTROL, SUBSH, TKN_LPAREN}};
	(*op_types)[4] = (t_op_types){")", 1, {CONTROL, SUBSH, TKN_RPAREN}};
	(*op_types)[5] = (t_op_types){"\n", 1, {CONTROL, CMD_END, TKN_NEWLINE}};
	(*op_types)[6] = (t_op_types){"&", 1, {CONTROL, CMD_END, TKN_AMP}};
	(*op_types)[7] = (t_op_types){";", 1, {CONTROL, CMD_END, TKN_SEMI}};
	(*op_types)[8] = (t_op_types){";;", 2, {CONTROL, CASE_END, TKN_DSEMI}};
	(*op_types)[9] = (t_op_types){";&", 2, {CONTROL, CASE_END, TKN_SEMIAMP}};
	(*op_types)[10] = (t_op_types){";;&", 3, {CONTROL, CASE_END, TKN_DSEMIAMP}};
	(*op_types)[11] = (t_op_types){"|&", 2, {CONTROL, PIPE, TKN_PIPEAMP}};
}

/*
	Fill the array token types with the redirection operators types.
	12 to 15 must be interpreted by miniShell.
	16 to 25 must not be interpreted by miniShell.
*/
void	fill_redir_op_types(t_op_types **op_types)
{
	(*op_types)[12] = (t_op_types){">", 1, {REDIR, IO_FILE, TKN_GREAT}};
	(*op_types)[13] = (t_op_types){">>", 2, {REDIR, IO_FILE, TKN_DGREAT}};
	(*op_types)[14] = (t_op_types){"<", 1, {REDIR, IO_FILE, TKN_LESS}};
	(*op_types)[15] = (t_op_types){"<<", 2, {REDIR, IO_HERE, TKN_DLESS}};
	(*op_types)[16] = (t_op_types){"<>", 2, {REDIR, IO_FILE, TKN_LESSGREAT}};
	(*op_types)[17] = (t_op_types){"<<<", 3, {REDIR, IO_S_HERE, TKN_TLESS}};
	(*op_types)[18] = (t_op_types){"<<-", 3, {REDIR, IO_HERE, TKN_DLESSDASH}};
	(*op_types)[19] = (t_op_types){"<&", 2, {REDIR, IO_DUP, TKN_LESSAMP}};
	(*op_types)[20] = (t_op_types){">&", 2, {REDIR, IO_DUP, TKN_GREATAMP}};
	(*op_types)[21] = (t_op_types){"&>", 2, {REDIR, IO_FILE, TKN_AMPGREAT}};
	(*op_types)[22] = (t_op_types){"&>>", 3, {REDIR, IO_FILE, TKN_AMPGREAT}};
	(*op_types)[23] = (t_op_types){">|", 2, {REDIR, IO_FILE, TKN_GREATPIPE}};
}

/*
	Returns an operator type if there is a match, 
	sinon retourne NULL;
*/
t_op_types	*get_op_type(char *s, int len, t_op_types *op_types)
{
	int		i;

	i = 0;
	while (op_types[i].type[0] != 0)
	{
		if (op_types[i].len == len && ft_strncmp(s, op_types[i].str, len) == 0)
			return (&op_types[i]);
		++i;
	}
	return (NULL);
}

/*
	Initialize and fill the array of token types.
*/
int	get_op_types(t_op_types **op_types)
{
	*op_types = (t_op_types *)ft_memalloc(sizeof(t_op_types) * 25);
	if (!*op_types)
		return (0);
	fill_control_op_types(op_types);
	fill_redir_op_types(op_types);
	(*op_types)[24] = (t_op_types){NULL, 0, {TKN_NULL, TKN_NULL, TKN_NULL}};
	return (1);
}
