#include "../includes/push_swap.h"

void pa(t_stack *stack_a, t_stack *stack_b)
{
    int value;

    if (is_empty(stack_b))
        return;
    value = pop(stack_b);
    push(stack_a, value);
    ft_printf("pa\n");
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    int value;

    if (is_empty(stack_a))
        return;
    value = pop(stack_a);
    push(stack_b, value);
    ft_printf("pb\n");
}
