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

static void	sort_large_array(t_stack *a, t_stack *b)
{
	push_all_but_three(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(a))
		shift_stack(a, 'a');
}

void	sort_turk(t_stack *a, t_stack *b)
{
	if (!a || !b || is_sorted(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else
		sort_large_array(a, b);
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
