/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:25:30 by mhug              #+#    #+#             */
/*   Updated: 2023/01/20 11:27:46 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "libft.h"

static void	init_btree_params(t_btree *root, t_btree_params **params)
{
	(*params)->tree_height = btree_level_count(root);
	(*params)->i_level = 0;
	(*params)->is_first_elem = 1;
}

static void	btree_apply_current_level(t_btree *root, int lvl, t_btree_params *p,
			void (*applyf)(void *item, int curent_level, int is_first_elem))
{
	if (!root)
		return ;
	if (lvl == 0)
	{
		applyf(root->item, p->i_level, p->is_first_elem);
		p->is_first_elem = 0;
	}
	else
	{
		btree_apply_current_level(root->left, lvl - 1, p, applyf);
		btree_apply_current_level(root->right, lvl - 1, p, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf) (void *item, int current_level, int is_first_elem))
{
	t_btree_params	*p;

	if (!root)
		return ;
	p = malloc(sizeof(t_btree_params));
	if (!p)
		return ;
	init_btree_params(root, &p);
	while (p->i_level < p->tree_height)
	{
		p->is_first_elem = 1;
		btree_apply_current_level(root, p->i_level, p, applyf);
		++p->i_level;
	}
	free(p);
}
