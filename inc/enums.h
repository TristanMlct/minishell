/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:26:04 by mhug              #+#    #+#             */
/*   Updated: 2023/03/02 11:30:15 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_tkn_type			t_tkn_type;
typedef enum e_state			t_state;
typedef enum e_error			t_error;

/*
	IO_DUP  expects a number (fd) but particular case filename
	IO_HERE expects a string (delimiter) → here_end
	IO_S_HERE expects a string (delimiter) → here_end
	IO_REDIR expects a string → filename
*/
enum e_tkn_type
{
	TKN_NULL=0,
	TKN_WORD,
	TKN_AMP,
	TKN_DAMP,
	TKN_PIPE,
	TKN_DPIPE,
	TKN_SEMI,
	TKN_DSEMI,
	TKN_SEMIAMP,
	TKN_DSEMIAMP,
	TKN_GREAT,
	TKN_DGREAT,
	TKN_LESSGREAT,
	TKN_LESS,
	TKN_DLESS,
	TKN_TLESS,
	TKN_DLESSDASH,
	TKN_LESSAMP,
	TKN_GREATAMP,
	TKN_AMPGREAT,
	TKN_AMPDGREAT,
	TKN_PIPEAMP,
	TKN_GREATPIPE,
	TKN_LPAREN,
	TKN_RPAREN,
	TKN_NEWLINE,
	TKN_BLANK,
	TKN_LBRACE,
	TKN_RBRACE,
	REDIR,
	CMD,
	CONTROL,
	SUBSH,
	GP_CMD,
	CMD_END,
	AND_OR,
	CASE_END,
	IO_FILE,
	IO_DUP,
	IO_HERE,
	IO_S_HERE,
	IO_REDIR,
	IO_CLOSE,
	PIPE,
	IO_NUMBER,
	FILENAME,
	HERE_END,
	ASSIGN_WORD,
	CMD_NAME,
	CMD_ARG,
};

/*
	If mode is_easy, we only have to handle the following states:
	(- S_START)
	- S_QUOTE 	→ 	''				|	(single quote)
	- S_DQUOTE 	→ 	"" or $""		|	(double quote)
	- S_PIPE	→ 	| cmd 			|	(pipe)
	- S_CMDOR 	→ 	|| cmd			|	(command or)
	- S_CMDAND 	→ 	&& cmd			|	(command and)
	- S_SUBSH 	→ 	(list)			|	(subshell)

	Other states (not implemented yet but could be)
	- S_QUOTE_ANSI_C →	$'cmd'		|	(single quote)
	- S_BQUOTE → 	`cmd` 			|	(command substitution)
	- S_ERRPIPE →	|& cmd 			|	(error pipe, eq to 2>&1 | cmd)
	- S_MATH → 		((expr))		| 	(arithmetic/math substitution)
	- S_CURSH → { list ;})			| 	(curly brace {+ws = reserved word)
	- S_CMDSUBST → 	$(cmd)			| 	(command substitution)
	- S_MATHSUBST → $((math))		| 	(math substitution)
	- S_MATHSUBST_SQ → $[math]		| 	(math substitution)
	- S_BRACEPARAM → ${param}		| 	(brace parameter expansion)

	Other states should be implemented in the future :
	→ like if, for, until, while, function, case etc...
	→ See reserved words, and compound commands
		(looping constructs, conditionnal constructs, grouping constructs)...
	→ process substitution ('<(list)' and '>(list)'))
*/
enum e_state
{
	S_START,
	S_QUOTE,
	S_QUOTE_ANSI_C,
	S_DQUOTE,
	S_BQUOTE,
	S_PIPE,
	S_ERRPIPE,
	S_CMDOR,
	S_CMDAND,
	S_SUBSH,
	S_MATH,
	S_CURSH,
	S_CMDSUBST,
	S_MATHSUBST,
	S_MATHSUBST_SQ,
	S_BRACEPARAM,
};

enum	e_error
{
	ERR_NONE,
	ERR_MALLOC,
	ERR_SYNTAX,
	ERR_STATES,
	ERR_NOT_IMPLEMENTED,
};

#endif