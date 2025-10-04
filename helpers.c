/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/10/04 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_min(t_stack *stack, char stack_name, int lowest_pos)
{
	while (lowest_pos > 0)
	{
		if (stack_name == 'a')
			ra(stack);
		else
			rb(stack);
		lowest_pos--;
	}
}

void	reverse_rotate_to_min(t_stack *stack, char stack_name,
		int lowest_pos, int stack_size)
{
	while (lowest_pos < stack_size)
	{
		if (stack_name == 'a')
			rra(stack);
		else
			rrb(stack);
		lowest_pos++;
	}
}

void	shift_stack(t_stack *stack, char stack_name)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = stack->size;
	lowest_pos = get_min_pos(stack);
	if (lowest_pos < stack_size - lowest_pos)
		rotate_to_min(stack, stack_name, lowest_pos);
	else
		reverse_rotate_to_min(stack, stack_name, lowest_pos, stack_size);
}

void	push_half_to_b(t_stack *a, t_stack *b)
{
	int	size;
	int	pushed;
	int	i;

	size = a->size;
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if (a->top->value <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
}

void	push_all_but_three(t_stack *a, t_stack *b)
{
	push_half_to_b(a, b);
	while (a->size > 3)
		pb(a, b);
}
