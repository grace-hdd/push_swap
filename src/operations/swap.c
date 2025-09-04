#include "../../includes/push_swap.h"

void sa(t_stack *stack)
{
    int temp;

    if (stack->size < 2)
        return;
    temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
}

void sb(t_stack *stack)
{
    int temp;

    if (stack->size < 2)
        return;
    temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}
