#include "minishell.h"

void	malloc_error(t_params *p)
{
	p->exit_code = ERR_MALLOC;
}

int	init_params(t_params **params, char **envp)
{
	if (!(*params = (t_params *)malloc(sizeof(t_params))))
		return (malloc_error(*params), 0);
	(*params)->pgm = "minishell";
	(*params)->env = NULL;
	(*params)->input = NULL;
	(*params)->op_types = NULL;
	(*params)->exit_code = EXIT_SUCCESS;
	if (!get_op_types(&(*params)->op_types))
		return (malloc_error(*params), 0);	
	if (!get_env_list(*params, envp))
		return (malloc_error(*params), 0);
	// display_lst_env((*params)->env); // DEBUG
	return (1);
}

void	clear_params(t_params **params)
{
	if (params && *params)
	{
		ft_strdel(&(*params)->input);
		ft_lstclear(&(*params)->env, &del_env);
		ft_memdel((void **)&(*params)->op_types);
		ft_memdel((void **)params);
	}
}
