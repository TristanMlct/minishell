/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert_after.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:04:41 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:04:50 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstinsert_after(t_dlist *elem, t_dlist *new)
{
	if (!elem || !new)
		return ;
	new->next = elem->next;
	new->prev = elem;
	elem->next = new;
	if (new->next)
		new->next->prev = new;
}
