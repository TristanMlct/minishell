/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:03:40 by mhug              #+#    #+#             */
/*   Updated: 2023/03/07 12:37:41 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env	t_env;

struct s_env
{
	char	*key;
	char	*value;
};

/* env.c */
int		add_or_update_env_var(t_list **env, char *key, char *value);
int		get_env_list(t_params *p, char **envp);

/* env_util.c */
t_env	*new_env_var(char *key, char *value);
void	del_env(void *env_var);
int		key_env_comp(void *env_var, char *key);

/* utils/env_display.c */ // DEBUG
void	display_lst_env(t_list *first_env_var);

#endif