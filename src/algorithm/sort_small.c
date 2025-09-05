#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(stack))
		return ;
	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	if (first > second && second > third)
		rra(stack);
	else if (first > second && second < third && first < third)
		sa(stack);
	else if (first < second && second > third && first < third)
		ra(stack);
	else if (first < second && second > third && first > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
	{
		sa(stack);
		ra(stack);
	}
}

