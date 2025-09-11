/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:45:04 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/11 12:54:08 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->array[i] == stack->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	parse_single_arg(char *arg, t_stack *stack)
{
	char	**numbers;
	int		i;
	long	num;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_integer(numbers[i]))
		{
			free(numbers);
			return (0);
		}
		num = ft_atol(numbers[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(numbers);
			return (0);
		}
		push_stack(stack, (int)num);
		i++;
	}
	free(numbers);
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	num;

	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		if (!parse_single_arg(argv[1], stack))
			return (0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!is_valid_integer(argv[i]))
				return (0);
			num = ft_atol(argv[i]);
			if (num > INT_MAX || num < INT_MIN)
				return (0);
			push_stack(stack, (int)num);
			i++;
		}
	}
	if (has_duplicates(stack))
		return (0);
	return (1);
}
