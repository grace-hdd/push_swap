/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;
	
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_front(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		return;
	new_node->next = *stack;
	*stack = new_node;
}

void	add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;
	
	if (!new_node)
		return;
	if (!*stack)
	{
		*stack = new_node;
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

void	remove_node_front(t_stack **stack)
{
	t_stack	*temp;
	
	if (!*stack)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
