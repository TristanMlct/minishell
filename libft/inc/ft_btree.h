/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:09:06 by mhug              #+#    #+#             */
/*   Updated: 2023/01/20 11:56:34 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

typedef struct s_btree_params
{
	int		tree_height;
	int		i_level;
	int		is_first_elem;
}				t_btree_params;

t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(t_btree **root,
			void *item, int (*cmpf)(void *, void *));
void	*btree_search_item(t_btree *root,
			void *data_ref, int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);
void	btree_apply_by_level(t_btree *root,
			void (*applyf) (void *item, int current_level, int is_first_elem));
void	btree_delone(t_btree **node, void (*del)(void *));
void	btree_clear(t_btree **root, void (*del)(void *));

#endif
