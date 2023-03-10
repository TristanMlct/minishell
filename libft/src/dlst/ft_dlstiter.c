/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:07:02 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:07:13 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter(t_dlist *head, void (*f)(void *))
{
	if (!head || !f)
		return ;
	while (head)
	{
		f(head->content);
		head = head->next;
	}
}
