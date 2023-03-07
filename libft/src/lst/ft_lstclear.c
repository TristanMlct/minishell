/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:26 by mhug              #+#    #+#             */
/*   Updated: 2022/11/08 19:50:22 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_delete;
	t_list	*elem;

	if (!lst || !del)
		return ;
	to_delete = NULL;
	elem = *lst;
	while (elem)
	{
		to_delete = elem;
		elem = elem->next;
		ft_lstdelone(to_delete, del);
	}
	*lst = NULL;
}
