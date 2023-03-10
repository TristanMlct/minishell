/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:57:07 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 08:57:59 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_back(t_dlist **head, t_dlist *new)
{
	t_dlist	*last;

	if (!new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		last = ft_dlstlast(*head);
		last->next = new;
		new->prev = last;
	}
}
