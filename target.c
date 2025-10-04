/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/10/04 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_position(t_stack *a, t_stack *b)
{
	t_node	*tmp_b;
	int		target_pos;

	tmp_b = b->top;
	while (tmp_b)
	{
		target_pos = get_target_pos(a, tmp_b->value);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

int	get_target_pos(t_stack *a, int b_value)
{
	t_node	*tmp_a;
	int		target_pos;
	int		target_value;
	int		pos;

	target_value = INT_MAX;
	target_pos = 0;
	pos = 0;
	tmp_a = a->top;
	while (tmp_a)
	{
		if (tmp_a->value > b_value && tmp_a->value < target_value)
		{
			target_value = tmp_a->value;
			target_pos = pos;
		}
		pos++;
		tmp_a = tmp_a->next;
	}
	if (target_value == INT_MAX)
		target_pos = get_min_pos(a);
	return (target_pos);
}

void	get_cost(t_stack *a, t_stack *b)
{
	t_node	*tmp_b;
	int		size_a;
	int		size_b;
	int		pos_b;

	tmp_b = b->top;
	size_a = a->size;
	size_b = b->size;
	pos_b = 0;
	while (tmp_b)
	{
		tmp_b->cost_b = pos_b;
		if (pos_b > size_b / 2)
			tmp_b->cost_b = (size_b - pos_b) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		pos_b++;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = b->top;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < abs(cheapest))
		{
			cheapest = abs(tmp->cost_a) + abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}

void	do_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(a, b, &cost_a, &cost_b);
	do_ra_rra(a, cost_a);
	do_rb_rrb(b, cost_b);
	pa(a, b);
}
