/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	if (stack->size == 2)
	{
		stack->top = second;
		stack->bottom = first;
		first->next = NULL;
		first->prev = second;
		second->prev = NULL;
		second->next = first;
	}
	else
	{
		first->next = second->next;
		first->prev = second;
		second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		stack->top = second;
	}
}

void	sa(t_stack *a)
{
	if (!a)
		return ;
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (!b)
		return ;
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
