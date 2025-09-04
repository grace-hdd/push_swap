#include "../includes/push_swap.h"

void print_error(void)
{
    ft_printf("Error\n");
    exit(1);
}

void cleanup_and_exit(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a)
        destroy_stack(stack_a);
    if (stack_b)
        destroy_stack(stack_b);
    ft_printf("Error\n");
    exit(1);
}

int validate_stack(t_stack *stack)
{
    if (!stack)
        return (0);
    if (stack->size < 0)
        return (0);
    return (1);
}