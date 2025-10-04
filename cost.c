/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/10/04 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	do_rrr(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	do_ra_rra(t_stack *a, int cost)
{
	while (cost)
	{
		if (cost > 0)
		{
			ra(a);
			cost--;
		}
		else
		{
			rra(a);
			cost++;
		}
	}
}

void	do_rb_rrb(t_stack *b, int cost)
{
	while (cost)
	{
		if (cost > 0)
		{
			rb(b);
			cost--;
		}
		else
		{
			rrb(b);
			cost++;
		}
	}
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
