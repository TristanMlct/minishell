/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:21:16 by mhug              #+#    #+#             */
/*   Updated: 2023/01/20 11:21:24 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
			void *data_ref, int (*cmpf)(void *, void *))
{
	t_btree	*next;

	if (root)
	{
		next = btree_search_item(root->left, data_ref, cmpf);
		if (next)
			return (next);
	}
	if (root && cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (root)
	{
		next = btree_search_item(root->right, data_ref, cmpf);
		if (next)
			return (next);
	}
	return (0);
}
