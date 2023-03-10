/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:08:09 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:08:25 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelone(t_dlist **head, t_dlist *elem, void (*del)(void *))
{
	if (!head || !elem || !del)
		return ;
	if (elem->prev)
		elem->prev->next = elem->next;
	else
		*head = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	del(elem->content);
	free(elem);
}
