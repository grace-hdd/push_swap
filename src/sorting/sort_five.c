/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_data *data)
{
	int	min_pos;
	int	i;
	
	while (data->size_a > 3)
	{
		min_pos = find_min_position(data->stack_a);
		move_to_top_a(data, min_pos);
		pb(data);
	}
	sort_three(data);
	while (data->size_b > 0)
		pa(data);
}

int	find_min_position(t_stack *stack)
{
	int		min_value;
	int		position;
	int		current_pos;
	t_stack	*current;
	
	min_value = stack->value;
	position = 0;
	current_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			position = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (position);
}

void	move_to_top_a(t_data *data, int position)
{
	int	mid;
	
	mid = data->size_a / 2;
	if (position <= mid)
	{
		while (position > 0)
		{
			ra(data);
			position--;
		}
	}
	else
	{
		while (position < data->size_a)
		{
			rra(data);
			position++;
		}
	}
}
