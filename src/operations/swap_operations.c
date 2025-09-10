/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_data *data)
{
	t_stack	*temp;
	
	if (data->size_a < 2)
		return;
	temp = data->stack_a->next;
	data->stack_a->next = temp->next;
	temp->next = data->stack_a;
	data->stack_a = temp;
	print_operation("sa");
}

void	sb(t_data *data)
{
	t_stack	*temp;
	
	if (data->size_b < 2)
		return;
	temp = data->stack_b->next;
	data->stack_b->next = temp->next;
	temp->next = data->stack_b;
	data->stack_b = temp;
	print_operation("sb");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	print_operation("ss");
}
