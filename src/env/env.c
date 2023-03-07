#include "minishell.h"

int	add_or_update_env_var(t_list **env, char *key, char *value)
{
	t_env	*env_var;
	t_list	*elem;

	elem = ft_lstfind(*env, key, key_env_comp);
	if (elem)
	{
		env_var = (t_env *)elem->content;
		ft_strdel(&env_var->value);
		env_var->value = ft_strdup(value);
		if (!env_var->value)
			return (0);
	}
	else
	{
		env_var = new_env_var(key, value);
		if (!env_var)
			return (0);
		ft_lstadd_back(env, ft_lstnew(env_var));
	}
	return (1);
}

/*
	TO DO : if envp is NULL, create a default env
*/
int	get_env_list(t_params *p, char **envp)
{
	int		i;
	char	**arr;

	i = -1;
	if (!p || !envp || !*envp)
		return (0);
	arr = NULL;
	while (envp[++i])
	{
		arr = ft_split_first(envp[i], '=');
		if (!arr)
			return (0);
		if (!add_or_update_env_var(&p->env, arr[0], arr[1]))
			return (ft_strarrdel(&arr), 0);
		ft_strarrdel(&arr);
	}
	return (1);
}
