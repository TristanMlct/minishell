/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:03:06 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:03:18 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstfind(t_dlist *head, void *content, int (*cmp)(void *, void *))
{
	if (!head || !content || !cmp)
		return (NULL);
	while (head)
	{
		if (cmp(head->content, content) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}
