/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_data *data)
{
	int	first;
	int	second;
	int	third;
	
	first = data->stack_a->value;
	second = data->stack_a->next->value;
	third = data->stack_a->next->next->value;
	
	if (first > second && second < third && first < third)
		sa(data);
	else if (first > second && second > third && first > third)
	{
		sa(data);
		rra(data);
	}
	else if (first > second && second < third && first > third)
		ra(data);
	else if (first < second && second > third && first < third)
	{
		sa(data);
		ra(data);
	}
	else if (first < second && second > third && first > third)
		rra(data);
}
