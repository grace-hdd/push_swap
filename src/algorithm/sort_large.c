#include "../includes/push_swap.h"

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	median;
	int	chunk_size;
	int	chunk_count;
	int	i;

	if (is_sorted(stack_a))
		return ;
	chunk_size = get_optimal_chunk_size(stack_a->size);
	chunk_count = (stack_a->size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < chunk_count)
	{
		median = get_median(stack_a);
		push_chunk_to_b(stack_a, stack_b, median, chunk_size);
		i++;
	}
	sort_stack_b(stack_a, stack_b);
}

int	get_optimal_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (15);
	else if (stack_size <= 500)
		return (30);
	else
		return (50);
}

void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int median, int chunk_size)
{
	int	pushed;
	int	operations;

	pushed = 0;
	while (pushed < chunk_size && stack_a->size > 0)
	{
		if (stack_a->top->value <= median)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
		{
			operations = find_best_rotation(stack_a, median);
			execute_rotations(stack_a, operations);
		}
	}
}

int	find_best_rotation(t_stack *stack, int median)
{
	t_node	*current;
	int		ra_count;
	int		rra_count;
	int		position;

	current = stack->top;
	ra_count = 0;
	while (current)
	{
		if (current->value <= median)
			break ;
		current = current->next;
		ra_count++;
	}
	if (!current)
		return (0);
	position = ra_count;
	rra_count = stack->size - position;
	if (ra_count <= rra_count)
		return (ra_count);
	else
		return (-rra_count);
}

void	execute_rotations(t_stack *stack, int operations)
{
	int	i;

	if (operations > 0)
	{
		i = 0;
		while (i < operations)
		{
			ra(stack);
			i++;
		}
	}
	else if (operations < 0)
	{
		i = 0;
		while (i < -operations)
		{
			rra(stack);
			i++;
		}
	}
}

void	sort_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	operations;

	while (stack_b->size > 0)
	{
		max = find_max(stack_b);
		operations = find_best_rotation(stack_b, max);
		execute_rotations(stack_b, operations);
		pa(stack_a, stack_b);
	}
}
