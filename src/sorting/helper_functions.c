/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_indexes(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;
	
	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	find_max_position(t_stack *stack)
{
	int		max_value;
	int		position;
	int		current_pos;
	t_stack	*current;
	
	max_value = stack->value;
	position = 0;
	current_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			position = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (position);
}

void	move_to_top_b(t_data *data, int position)
{
	int	mid;
	
	mid = data->size_b / 2;
	if (position <= mid)
	{
		while (position > 0)
		{
			rb(data);
			position--;
		}
	}
	else
	{
		while (position < data->size_b)
		{
			rrb(data);
			position++;
		}
	}
}
