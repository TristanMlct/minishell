/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:01:27 by mhug              #+#    #+#             */
/*   Updated: 2023/03/07 13:11:14 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_lexer			t_lexer;
typedef struct s_token			t_token;
typedef struct s_op_types		t_op_types;
typedef struct s_stack			t_stack;
typedef struct s_redir			t_redir;

struct s_lexer
{
	t_token			*head;
	t_token			*tail;
	t_token			*unexpected;
	t_stack			*states;
	t_list			*heredoc;
	int				is_basic;
};

struct s_token
{
	char			*str;
	int				len;
	t_tkn_type		type[3];
	t_token			*cmd;
	t_token			*next;
	t_token			*prev;
};

struct s_redir
{
	char			*file;
	int				fd_in;
	int				fd_out;
	t_tkn_type		type;
	t_token			*token;
//	t_redir			*next;
};

struct	s_op_types
{
	char		*str;
	int			len;
	t_tkn_type	type[3];
};

struct	s_stack
{
	t_state	state;
	t_stack	*next;
};

/* lexer.c */
int			add_next_token(t_lexer *lexer, char *str, int *i, t_op_types *op);
t_lexer		*get_lexer(char *str, t_op_types *op_types, int *err);

/* lexer_utils.c */
int			init_lexer(t_lexer **lexer);
void		clear_lexer(t_lexer **lexer);
int			all_states_are_closed(t_lexer *lexer);
/* /!\ temporary function */
void		print_error(int err, t_lexer *lexer);

/* states.c */
int			update_quote_state(t_lexer *lexer, char *str, int i);
void		update_control_state(t_lexer *lexer, t_token *token);
void		update_state(t_lexer *lexer, int error);

/* states_stack.c */
t_stack		*ft_stack_new(t_state state);
void		ft_stack_push(t_stack **stack, t_state state);
void		ft_stack_pop(t_stack **stack);
t_state		ft_stack_peek(t_stack *stack);
void		ft_stack_clear(t_stack **stack);

/* states_utils.c */
void		ft_stack_init(t_stack **stack);
int			is_quoted(t_lexer *lexer);

/* operators.c */
void		fill_control_op_types(t_op_types **op_types);
void		fill_redir_op_types(t_op_types **op_types);
t_op_types	*get_op_type(char *s, int len, t_op_types *op_types);
int			get_op_types(t_op_types **op_types);

/* tokens.c */
int			init_token(t_token **token, char *str, int len, int type);
t_token		*get_blank_token(char *str, int i);
t_token		*get_op_token(t_lexer *lexer, char *str, int i, t_op_types *op);
t_token		*get_word_token(t_lexer *lexer, char *str, int i);

/* tokens_update.c */
int			is_an_assignment_word(t_token *token);
int			there_is_not_a_cmd_name_in_simple_command(t_token *token);
void		update_word_token_type(t_token *token, t_token *prev);
void		update_token_type(t_lexer *lexer, int error);

/* tokens_utils_dlst.c */
void		tkn_dlstdelone(t_lexer *lexer, t_token *token);
void		recursive_del(t_token *token);
void		tkn_dlstclear(t_lexer *lexer);
void		tkn_dlstadd_back(t_lexer *lexer, t_token *new);
void		tkn_dlstinsert_before(t_lexer *lexer, t_token *token, t_token *new);

/* tokens_utils.c */
void		free_token(t_token **token);
t_token		*prev_relevant_token(t_token *token);
int			is_metacharacter(char c);
int			is_word_token(t_lexer *lexer, char c);
int			is_last_newline_escaped(t_lexer *lexer, char *str, int i);

/* syntaxe.c */
void		check_control_op_syntax(
				t_lexer *lexer, t_token *token, t_token *prev);
void		check_redir_op_syntax(
				t_lexer *lexer, t_token *token, t_token *prev);
void		check_tkn_word_syntax(t_lexer *lexer, t_token *token);
void		check_syntax(t_lexer *lexer, int *error);

/* syntaxe_utils.c */
void		check_braces_syntax(t_lexer *lexer, t_token *token, t_token *prev);
void		check_newline_syntax(t_lexer *lexer, t_token *token, t_token *prev);
int			follows_gp_cmd(t_token *token);

/* syntaxe_utils2.c */
int			in_subsh(t_stack *states);
int			in_case_command(t_lexer *lexer);
int			in_function(t_lexer *lexer);
int			last_control_op_is(t_token *token, t_tkn_type type, int index);
int			is_first_tkn_word_in_cmd(t_token *token);

/* str_utils.c */
int			is_only_spaces(char *str);

/* displays.c */ // DEBUG TO REMOVE
void		display_op_types(t_op_types *t);
char		*state_to_display(t_state state);
char		*token_to_display(t_token *token);
void		display_tokens(t_lexer *lexer);
char		*token_type(t_tkn_type type);
void		display_stack(t_stack *stack);
void		recursive_token_display(t_lexer *lexer, t_token *token);

#endif
