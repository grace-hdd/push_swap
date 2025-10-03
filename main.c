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

static void	assign_indices_to_stack(t_stack *stack, int *numbers, int count)
{
	t_node	*current;
	int		i;
	int		j;
	int		rank;

	current = stack->top;
	while (current)
	{
		rank = 0;
		j = 0;
		while (j < count)
		{
			if (numbers[j] < current->value)
				rank++;
			j++;
		}
		current->index = rank;
		current = current->next;
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
		push_bottom(stack, node);
		i++;
	}
	assign_indices_to_stack(stack, numbers, count);
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
