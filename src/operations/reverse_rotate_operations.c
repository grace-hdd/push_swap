/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_data *data)
{
	t_stack	*temp;
	t_stack	*last;
	
	if (data->size_a < 2)
		return;
	last = data->stack_a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = data->stack_a;
	data->stack_a = temp;
	print_operation("rra");
}

void	rrb(t_data *data)
{
	t_stack	*temp;
	t_stack	*last;
	
	if (data->size_b < 2)
		return;
	last = data->stack_b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = data->stack_b;
	data->stack_b = temp;
	print_operation("rrb");
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	print_operation("rrr");
}
