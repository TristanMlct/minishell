#include "minishell.h"

t_env	*new_env_var(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	return (new);
}

void	del_env(void *env_var)
{
	t_env	*tmp;

	tmp = (t_env *)env_var;
	ft_strdel(&(tmp->key));
	ft_strdel(&(tmp->value));
	free(tmp);
}

int	key_env_comp(void *env_var, char *key)
{
	t_env	*tmp;

	tmp = (t_env *)env_var;
	if (ft_strcmp(tmp->key, key) == 0)
		return (0);
	return (1);
}
