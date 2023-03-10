/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert_before.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:05:46 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:05:52 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstinsert_before(t_dlist **head, t_dlist *token, t_dlist *new)
{
	if (! head || !token || !new)
		return ;
	new->next = token;
	new->prev = token->prev;
	token->prev = new;
	if (new->prev)
		new->prev->next = new;
	else
		*head = new;
}
