/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:28:23 by mhug              #+#    #+#             */
/*   Updated: 2023/03/07 13:07:53 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_input(char *input, t_op_types *op_types)
{
	t_lexer	*lexer;
	int		err;
	// t_ast	*ast;

	lexer = NULL;
	err = 0;
	if (input && !is_only_spaces(input))
	{
		lexer = get_lexer(input, op_types, &err);
		display_stack(lexer->states); // DEBUG
		// display_tokens(lexer); // DEBUG
		if (lexer && !err)
		{
			if (pre_parse(lexer, &err))
			{
				recursive_token_display(lexer, lexer->head); // DEBUG
				display_tokens(lexer); // DEBUG
				// ast = convert_tokens_to_ast(lexer);
			}
		}
		if (err)
			print_error(err, lexer); // TEMP function !
		add_history(input);
	}
	if (input)
	{
		ft_strdel(&input);
		clear_lexer(&lexer);
	}
	return (err);
}

int	main(int argc, char **argv, char **envp)
{
	t_params	*params;
//	char		*line;

	(void)argc;
	(void)argv;
	if (!init_params(&params, envp))
		return (clear_params(&params), EXIT_FAILURE);
	/*while (42)
	{
		line = readline("minishell> ");
		if (!line)
			break ; // TODO: handle error
		if (ft_strcmp(line, "exit") == 0) // TEMP
		{
			ft_strdel(&line);
			clear_params(&params);
			break ;
		}
		else if (ft_strcmp(line, "op") == 0) // TEMP
		{
			ft_strdel(&line);
			display_op_types(params->op_types);
			continue ;
		}
		// process_input(line, op_types);
	}*/
	return (clear_params(&params), EXIT_SUCCESS);
}
