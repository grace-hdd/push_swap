/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	rotate_to_pos(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
		while (pos-- > 0)
			ra(stack);
	else
		while (pos++ < stack->size)
			rra(stack);
}

void	push_min_to_b(t_stack *a, t_stack *b, int *size)
{
	int	min_pos;
	int	rotations;

	min_pos = get_min_pos(a);
	if (min_pos <= *size / 2)
	{
		rotations = min_pos;
		while (rotations-- > 0)
			ra(a);
	}
	else
	{
		rotations = *size - min_pos;
		while (rotations-- > 0)
			rra(a);
	}
	pb(a, b);
	(*size)--;
}
