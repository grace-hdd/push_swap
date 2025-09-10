/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_data *data)
{
	t_stack	*temp;
	
	if (data->size_b == 0)
		return;
	temp = data->stack_b;
	data->stack_b = data->stack_b->next;
	temp->next = data->stack_a;
	data->stack_a = temp;
	data->size_a++;
	data->size_b--;
	print_operation("pa");
}

void	pb(t_data *data)
{
	t_stack	*temp;
	
	if (data->size_a == 0)
		return;
	temp = data->stack_a;
	data->stack_a = data->stack_a->next;
	temp->next = data->stack_b;
	data->stack_b = temp;
	data->size_a--;
	data->size_b++;
	print_operation("pb");
}
