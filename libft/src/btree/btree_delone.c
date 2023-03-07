/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:46:04 by mhug              #+#    #+#             */
/*   Updated: 2023/01/20 11:52:42 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "libft.h"

void	btree_delone(t_btree **node, void (*del)(void *))
{
	if (!*node)
		return ;
	if (del)
		del((*node)->item);
	ft_free((void **)node);
}
