/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_data *data)
{
	t_stack	*temp;
	t_stack	*last;
	
	if (data->size_a < 2)
		return;
	temp = data->stack_a;
	data->stack_a = data->stack_a->next;
	last = data->stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	print_operation("ra");
}

void	rb(t_data *data)
{
	t_stack	*temp;
	t_stack	*last;
	
	if (data->size_b < 2)
		return;
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	last = data->stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	print_operation("rb");
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	print_operation("rr");
}
