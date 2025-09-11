/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:55:08 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/11 12:55:16 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;

	if (data->a->size != 3)
		return ;
	first = data->a->array[0];
	second = data->a->array[1];
	third = data->a->array[2];
	if (first > second && second < third && first < third)
		sa(data, 1);
	else if (first > second && second > third && first > third)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (first > second && second < third && first > third)
		ra(data, 1);
	else if (first < second && second > third && first < third)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (first < second && second > third && first > third)
		rra(data, 1);
}

void	sort_small(t_data *data)
{
	int	min_index;
	int	size;

	while (data->a->size > 3)
	{
		min_index = find_min_index(data->a);
		size = data->a->size;
		if (min_index <= size / 2)
		{
			while (min_index > 0)
			{
				ra(data, 1);
				min_index--;
			}
		}
		else
		{
			while (min_index < size)
			{
				rra(data, 1);
				min_index++;
			}
		}
		pb(data, 1);
	}
	if (data->a->size == 3)
		sort_three(data);
	else if (data->a->size == 2 && data->a->array[0] > data->a->array[1])
		sa(data, 1);
	while (!is_empty(data->b))
		pa(data, 1);
}

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;
	int	i;

	max = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_data *data)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	normalize_stack(data->a);
	max_bits = get_max_bits(data->a);
	bit = 0;
	while (bit < max_bits)
	{
		size = data->a->size;
		i = 0;
		while (i < size)
		{
			if ((data->a->array[0] >> bit) & 1)
				ra(data, 1);
			else
				pb(data, 1);
			i++;
		}
		while (!is_empty(data->b))
			pa(data, 1);
		bit++;
	}
}

void	sort_stack(t_data *data)
{
	if (is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
		sort_small(data);
	else
		radix_sort(data);
}
