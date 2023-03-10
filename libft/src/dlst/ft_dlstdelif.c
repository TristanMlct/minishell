/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:14:31 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:16:53 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelif(t_dlist **head, void *data_ref,
			int (*cmp)(), void (*del)(void *))
{
	t_dlist	*to_del;
	t_dlist	*elem;
	t_dlist	*prev;

	elem = *head;
	prev = NULL;
	while (elem)
	{
		if (cmp(elem->content, data_ref) == 0)
		{
			if (!prev)
				*head = elem->next;
			else
				prev->next = elem->next;
			to_del = elem;
			elem = elem->next;
			ft_dlstdelone(head, to_del, del);
		}
		else
		{
			prev = elem;
			elem = elem->next;
		}
	}
}
