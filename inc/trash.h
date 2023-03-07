/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:30:29 by mhug              #+#    #+#             */
/*   Updated: 2023/03/02 11:30:30 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASH_H
# define TRASH_H

/*
	tokens are separed by unquoted metacharacters.
	metacharacter = ws | | | & | ; | ( | ) | < | > | 
	blanks = space | tab | newline
	token = word | control_operator | redirection_operator |
	control_operator = ; | ;; | & | && | | | || | |& | ( | ) | newline
	redirection_operator = < | > | >| | << | >> | <> | >& | <& | <<- | <<<
*/

typedef enum e_keyword		t_keyword;
typedef enum e_builtin		t_builtin;

/*
	Enum for the different types of keywords (or reserved words) from bash.
	1. looping constructs : 
		while, until, for, in, do, done.
	2. Conditionnal constructs : 
		[[, ]], if, then, else, elif, fi, case, esac, select, coproc.
	3. Command grouping :
		"{ws", ";[or_other_terminator?][ws]}".
	4. Pipelines :
		!, time.
	5. Functions :
		function.
*/
enum e_keyword
{
	KW_WHILE,
	KW_UNTIL,
	KW_FOR,
	KW_IN,
	KW_DO,
	KW_DONE,
	KW_D_LBRACKET,
	KW_D_RBRACKET,
	KW_IF,
	KW_THEN,
	KW_ELSE,
	KW_ELIF,
	KW_FI,
	KW_CASE,
	KW_ESAC,
	KW_SELECT,
	KW_COPROC,
	KW_LBRACE,
	KW_RBRACE,
	KW_BANG,
	KW_TIME,
	KW_FUNCTION,
};

enum e_builtin
{
	BT_ECHO,
	BT_CD,
	BT_PWD,
	BT_EXPORT,
	BT_UNSET,
	BT_ENV,
	BT_EXIT,
};

/*
	Enum for the quoting.

	UNQUOTED → no quotes. 
		meta-characters, keywords and special characters are interpreted.
	QUOTED → 'string' (single quotes).
	DQUOTED → "string" (double quotes).
		variables are expanded, command substitution is performed.
		
	ANSI_C_QUOTED → $'string'
		'\n', '\t', '\v', '\b', '\r', '\f', '\a', '\e'...
		interpreted as special characters.
	add $"" for local specific translation ??
*/

/*
	symbol	| name		|	precision
	1. Control Operators
x	&		| amp		 |	cmd_list terminator in async execution (bg)
x	;		| semi		|	cmd_list terminator in sequencial execution (fg)
x	;;		| dsemi		|	(case statement only)
x	;&		| semiamp	|	(case statement only))
x	;;&		| dsemiamp	|	(case statement only))
	&&		| damp		|	logical and
	||		| dpipe		|	logical or
	'\n'	| newline	|	-
	|		| pipe		|	-
x	|&		| pipeamp	|	errpipe eq to "2>&1 |" (stdout and stderr are piped)
	(		| lparen	|	group commands, executed in subshell (start)
	)		| rparen	|	group commands, executed in subshell (end)

	2. Redirection Operators

	NOTES : 
		- [n] is an optional file descriptor number.
		- wd is a word (a sequence of characters that are neither 
		control operators nor redirection operators).
		  It can be submitted to word splitting and pathname expansion.
		- x means that the operator is not implemented by minishell.

	[n]> wd		| great			|	O_redir (O_TRUNC mode)
x	[n]>| wd	| greatpipe		|	O_redir forced 
										(if noclobber is set and file exists)
	[n]>> wd	| dgreat		|	O_redir (O_APPEND mode)
	[n]< wd		| less			|	I_redir (O_RDONLY mode) ???
	[n]<< wd	| dless			|	I_redir (HEREDOC mode, with word delimiter)
										if wd is unquoted:
											- parameter and variable expansion
											- command substitution
											- arithmetic expansion
											- '\' is an escape character							
x	[n]<<- wd	| dlessdash		|	I_redir (HEREDOC mode, 
										with leading tab characters stripped 
										→ allow shell scripts indentation )
x	[n]<<< wd	| tless			|	I_redir (HERESTRING mode)
										(expansions, substitutions performed)
x 	&>wd		| ampgreat		|	O_redir to file.
										- eq to "> wd 2>&1" 
										(stdout + stderr redirected to file)
x	[n]&>>wd	| ampdgreat		|	O_redir to file (eq &>wd but append mode)
x	[n]>&wd		| greatamp		|	O_dup
										Used to duplicate output fd.
									if wd expands to a number: (usual case)
										n (1 by default) is dup of the fd wd.
									if wd expands to '-':
										n (1 by default) is closed.
									if n omitted and wd a filename: (particular)
										- eq to &>wd → "> wd 2>&1" 
										(stdout + stderr redirected to file wd)
										(syntax &> is preferred over >&)
									NB : [n]<&digit- moves the fd digit to fd n.
									(or stdout if n not specified)
									digit is closed after being duplicated to n.
x	[n]<&wd		| lessamp		|	I_dup
										Used to duplicate input fd.
									if wd expands to a number:
										n (0 by default) is dup from wd.
									if wd expands to '-':
										n is closed (0 by default)
									if wd does not expand to a number or '-':
										- error (ambiguous redirect) (code 1)
									NB : [n]<&digit- moves the fd digit to fd n.
									(or stdin if n not specified)
									digit is closed after being duplicated to n.
x	[n]<>wd		| lessgreat		|	IO_redir
									open file (expanded from wd) (r+w) on n 
									(or 0 by default).

	3. Words
	Words are sequences of characters that are neither control operators 
	nor redirection operators.
*/

#endif