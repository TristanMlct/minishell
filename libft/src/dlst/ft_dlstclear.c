/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:11:02 by mhug              #+#    #+#             */
/*   Updated: 2023/03/10 09:11:06 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_dlstdelone(lst, tmp, del);
	}
	*lst = NULL;
}
