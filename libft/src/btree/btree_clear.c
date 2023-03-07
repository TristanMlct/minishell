/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:53:47 by mhug              #+#    #+#             */
/*   Updated: 2023/01/20 11:58:55 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

//	btree_apply_suffix(*root, btree_delone);
void	btree_clear(t_btree **root, void (*del)(void *))
{
	if (!*root)
		return ;
	btree_clear(&(*root)->left, del);
	btree_clear(&(*root)->right, del);
	btree_delone(root, del);
}
