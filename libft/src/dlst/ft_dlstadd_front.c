/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:00:01 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:00:11 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **head, t_dlist *new)
{
	if (!new)
		return ;
	if (head && *head)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;
}
