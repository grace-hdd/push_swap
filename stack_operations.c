/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:52:02 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/11 12:52:11 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->array)
			free(stack->array);
		free(stack);
	}
}

void	push_stack(t_stack *stack, int value)
{
	int	i;

	if (!stack || stack->size >= stack->capacity)
		return ;
	i = stack->size;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = value;
	stack->size++;
}

int	pop_stack(t_stack *stack)
{
	int	value;
	int	i;

	if (!stack || stack->size == 0)
		return (0);
	value = stack->array[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->size--;
	return (value);
}

int	peek_stack(t_stack *stack, int index)
{
	if (!stack || index >= stack->size)
		return (0);
	return (stack->array[index]);
}

int	is_empty(t_stack *stack)
{
	return (!stack || stack->size == 0);
}
