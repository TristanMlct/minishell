/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:57:24 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/09 13:27:15 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (!lst)
		return ;
	if (!del)
		return ;
	while (*lst)
	{
		elem = *lst;
		*lst = (*lst)->next;
		del(elem->content);
		free(elem);
	}
}
