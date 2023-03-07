/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:22:02 by mhug              #+#    #+#             */
/*   Updated: 2023/02/27 17:45:15 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stack	*ft_stack_new(t_state state)
{
	t_stack	*elem;

	elem = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->state = state;
	elem->next = NULL;
	return (elem);
}

/*
	Pushes an element to the stack.
	(Adds to the beginning of the list)
*/
void	ft_stack_push(t_stack **stack, t_state state)
{
	t_stack	*elem;

	elem = ft_stack_new(state);
	if (!elem)
		return ;
	elem->next = *stack;
	*stack = elem;
}

/*
	Pops an element from the stack.
	(Removes the last element added, at the beginning of the list)
*/
void	ft_stack_pop(t_stack **stack)
{
	t_stack	*to_delete;

	if (!*stack)
		return ;
	to_delete = *stack;
	*stack = (*stack)->next;
	free(to_delete);
}

/*
	Returns the data of the last element added to the stack.
*/
t_state	ft_stack_peek(t_stack *stack)
{
	if (!stack)
		return (-1);
	return (stack->state);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*elem;
	t_stack	*to_delete;

	elem = *stack;
	while (elem)
	{
		to_delete = elem;
		elem = elem->next;
		free(to_delete);
	}
	*stack = NULL;
}
