/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	parse_arguments(int argc, char **argv, t_data *data)
{
	int		i;
	
	i = 1;
	while (i < argc)
	{
		if (!parse_string_argument(argv[i], data))
			return (0);
		i++;
	}
	return (check_duplicates(data->stack_a));
}

int	parse_string_argument(char *str, t_data *data)
{
	char	**numbers;
	int		i;
	int		value;
	t_stack	*new_node;
	
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!validate_number(numbers[i]))
		{
			free_string_array(numbers);
			return (0);
		}
		value = ft_atoi(numbers[i]);
		new_node = create_node(value);
		if (!new_node)
		{
			free_string_array(numbers);
			return (0);
		}
		add_node_back(&data->stack_a, new_node);
		i++;
	}
	free_string_array(numbers);
	return (1);
}

int	validate_number(char *str)
{
	int	i;
	
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;
	
	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	int	size;
	
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
