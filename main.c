/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_value_index_map(int *numbers, int count)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < count)
	{
		rank = 0;
		j = 0;
		while (j < count)
		{
			if (numbers[j] < numbers[i])
				rank++;
			j++;
		}
		numbers[i] = rank;
		i++;
	}
}

static t_stack	*create_stack_from_array(int *numbers, int count)
{
	t_stack	*stack;
	t_node	*node;
	int		i;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 0;
	while (i < count)
	{
		node = create_node(numbers[i]);
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		node->index = numbers[i];
		push_bottom(stack, node);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		count;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &numbers, &count))
	{
		print_error();
		return (1);
	}
	create_value_index_map(numbers, count);
	a = create_stack_from_array(numbers, count);
	b = init_stack();
	if (!a || !b)
	{
		free(numbers);
		return (1);
	}
	push_swap(a, b);
	free(numbers);
	free_stack(a);
	free_stack(b);
	return (0);
}
