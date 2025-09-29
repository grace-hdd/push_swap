/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	first = pop_top(stack);
	push_bottom(stack, first);
}

void	ra(t_stack *a)
{
	if (!a)
		return ;
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (!b)
		return ;
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}
