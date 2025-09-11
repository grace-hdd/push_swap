#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->size <= 1)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int	min;
	int	min_index;
	int	i;

	if (!stack || stack->size == 0)
		return (-1);
	min = stack->array[0];
	min_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
		{
			min = stack->array[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_max_index(t_stack *stack)
{
	int	max;
	int	max_index;
	int	i;

	if (!stack || stack->size == 0)
		return (-1);
	max = stack->array[0];
	max_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] > max)
		{
			max = stack->array[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

void	normalize_stack(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;
	int	rank;

	sorted = malloc(sizeof(int) * stack->size);
	if (!sorted)
		return ;
	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->array[i];
		i++;
	}
	i = 0;
	while (i < stack->size - 1)
	{
		j = 0;
		while (j < stack->size - 1 - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				int temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		rank = 0;
		while (j < stack->size)
		{
			if (sorted[j] < stack->array[i])
				rank++;
			j++;
		}
		stack->array[i] = rank;
		i++;
	}
	free(sorted);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}
