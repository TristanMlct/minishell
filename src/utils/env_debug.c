#include "minishell.h"

void	display_lst_env(t_list *first_env_var)
{
	t_list	*tmp;
	t_env	*tmp_env;

	tmp = first_env_var;
	while (tmp != NULL)
	{
		tmp_env = tmp->content;
		ft_printf("key: %s, value: %s\n", tmp_env->key, tmp_env->value);
		tmp = tmp->next;
	}
}
