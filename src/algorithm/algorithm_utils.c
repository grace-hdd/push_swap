#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int value)
{
	t_node	*current;
	int		position;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}
	return (0);
}

int	get_median(t_stack *stack)
{
	int	*values;
	int	i;
	int	j;
	int	temp;
	int	median;

	if (!stack || stack->size == 0)
		return (0);
	values = (int *)malloc(stack->size * sizeof(int));
	if (!values)
		return (0);
	i = 0;
	while (i < stack->size)
	{
		values[i] = get_value_at_position(stack, i);
		i++;
	}
	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
	median = values[stack->size / 2];
	free(values);
	return (median);
}

int	get_value_at_position(t_stack *stack, int position)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->top || position >= stack->size)
		return (0);
	current = stack->top;
	i = 0;
	while (i < position)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

int	count_operations_to_top(t_stack *stack, int value)
{
	int	position;
	int	size;

	position = get_position(stack, value);
	size = stack->size;
	if (position <= size / 2)
		return (position);
	else
		return (size - position);
}
