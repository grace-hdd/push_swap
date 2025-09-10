/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	
	// Initialize data structure
	data.stack_a = NULL;
	data.stack_b = NULL;
	data.size_a = 0;
	data.size_b = 0;
	
	// Parse arguments and create stack A
	if (!parse_arguments(argc, argv, &data))
	{
		error_exit(&data);
		return (1);
	}
	
	// Check if already sorted
	if (is_sorted(data.stack_a))
	{
		free_stack(&data.stack_a);
		return (0);
	}
	
	// Assign indexes for easier sorting
	assign_indexes(data.stack_a);
	
	// Choose sorting algorithm based on stack size
	data.size_a = stack_size(data.stack_a);
	if (data.size_a <= 3)
		sort_three(&data);
	else if (data.size_a <= 5)
		sort_five(&data);
	else
		sort_large(&data);
	
	// Clean up
	free_stack(&data.stack_a);
	free_stack(&data.stack_b);
	
	return (0);
}
