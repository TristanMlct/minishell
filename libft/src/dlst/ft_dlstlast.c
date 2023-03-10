/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:59:09 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 08:59:15 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlast(t_dlist *head)
{
	t_dlist	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
