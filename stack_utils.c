/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*bottom;
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	if (stack->size == 1)
	{
		bottom = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		current = stack->top;
		while (current->next->next)
			current = current->next;
		bottom = current->next;
		current->next = NULL;
		stack->bottom = current;
	}
	stack->size--;
	return (bottom);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
