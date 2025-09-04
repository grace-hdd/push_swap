#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_a = init_stack_a(argc, argv);
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_b = create_stack();
	if (!stack_b)
	{
		destroy_stack(stack_a);
		ft_printf("Error\n");
		return (1);
	}
	if (stack_a->size <= 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return (0);
}