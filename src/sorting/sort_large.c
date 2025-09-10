/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_large(t_data *data)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	
	chunk_size = data->size_a / 4;
	chunk_start = 0;
	chunk_end = chunk_size;
	while (data->size_a > 0)
	{
		push_chunk_to_b(data, chunk_start, chunk_end);
		chunk_start = chunk_end;
		chunk_end += chunk_size;
		if (chunk_end > data->size_a)
			chunk_end = data->size_a;
	}
	while (data->size_b > 0)
	{
		find_and_push_max(data);
	}
}

void	push_chunk_to_b(t_data *data, int start, int end)
{
	int	i;
	
	i = 0;
	while (i < data->size_a && data->size_a > 0)
	{
		if (data->stack_a->index >= start && data->stack_a->index < end)
		{
			pb(data);
		}
		else
		{
			ra(data);
		}
		i++;
	}
}

void	find_and_push_max(t_data *data)
{
	int	max_pos;
	
	max_pos = find_max_position(data->stack_b);
	move_to_top_b(data, max_pos);
	pa(data);
}
