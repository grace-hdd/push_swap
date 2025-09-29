/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	int	first;
	int	second;

	if (!a || a->size != 2)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	if (first > second)
		sa(a);
}

static void	sort_three_case(t_stack *a, int *values)
{
	if (values[0] > values[1] && values[1] < values[2] && values[0] < values[2])
		sa(a);
	else if (values[0] > values[1] && values[1] > values[2])
	{
		sa(a);
		rra(a);
	}
	else if (values[0] > values[1] && values[1] < values[2]
		&& values[0] > values[2])
		ra(a);
	else if (values[0] < values[1] && values[1] > values[2]
		&& values[0] < values[2])
	{
		sa(a);
		ra(a);
	}
	else if (values[0] < values[1] && values[1] > values[2]
		&& values[0] > values[2])
		rra(a);
}

void	sort_three(t_stack *a)
{
	int		values[3];
	t_node	*current;

	if (!a || a->size != 3)
		return ;
	current = a->top;
	values[0] = current->value;
	current = current->next;
	values[1] = current->value;
	current = current->next;
	values[2] = current->value;
	sort_three_case(a, values);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	size;

	if (!a || !b || a->size > 5)
		return ;
	size = a->size;
	while (size > 3)
	{
		push_min_to_b(a, b, &size);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
}
