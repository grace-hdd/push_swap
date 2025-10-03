/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_chunk(t_stack *a, t_stack *b, int range, int *chunk)
{
	int	pos;

	pos = get_min_pos(a);
	if (a->top->index <= *chunk * range)
	{
		pb(a, b);
		*chunk = (b->size - 1) / range + 1;
	}
	else if (pos <= a->size / 2)
		ra(a);
	else
		rra(a);
}

void	sort_turk(t_stack *a, t_stack *b)
{
	int	size;
	int	chunk;
	int	range;

	if (!a || !b || is_sorted(a))
		return ;
	size = a->size;
	chunk = 0;
	if (size <= 100)
		range = size / 3;
	else
		range = size / 8;
	while (a->size > 3)
		process_chunk(a, b, range, &chunk);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_turk(a, b);
}
