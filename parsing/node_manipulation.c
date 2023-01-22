/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:36:48 by tmilcent          #+#    #+#             */
/*   Updated: 2023/01/22 18:34:05 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_node	*create_node()
{
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == 0)
		return (0);
	new_node->arg = 0;
	new_node->left = 0;
	new_node->right = 0;
	new_node->type = UNKNOWN;
	return (new_node);
}

void	print_node(t_node node)
{
	printf("===============\n");
	printf("Node type -> %d\n", node.type);
	printf("Node arg  -> %s\n", node.arg);
	printf("===============\n");
}