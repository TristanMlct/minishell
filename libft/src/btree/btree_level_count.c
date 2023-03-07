/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:22:50 by mhug              #+#    #+#             */
/*   Updated: 2023/01/20 11:23:45 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "libft.h"

int	btree_level_count(t_btree *root)
{
	int	max_left;
	int	max_right;

	if (!root)
		return (0);
	max_left = btree_level_count(root->left);
	max_right = btree_level_count(root->right);
	return (1 + ft_max(max_left, max_right));
}
