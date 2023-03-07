/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:17:42 by mhug              #+#    #+#             */
/*   Updated: 2023/01/20 11:17:46 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root,
		void *item, int (*cmpf)(void *, void *))
{
	if (!*root)
		*root = btree_create_node(item);
	else if (cmpf(item, (*root)->item) >= 0)
		btree_insert_data(&(*root)->right, item, cmpf);
	else
		btree_insert_data(&(*root)->left, item, cmpf);
}
