#include "../includes/push_swap.h"

void sa(t_stack *stack)
{
    int temp;

    if (stack->size < 2)
        return;
    temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
    ft_printf("sa\n");
}

void sb(t_stack *stack)
{
    int temp;

    if (stack->size < 2)
        return;
    temp = stack->top->value;
    stack->top->value = stack->top->next->value;
    stack->top->next->value = temp;
    ft_printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    int temp_a;
    int temp_b;

    if (stack_a->size < 2 || stack_b->size < 2)
        return;
    temp_a = stack_a->top->value;
    stack_a->top->value = stack_a->top->next->value;
    stack_a->top->next->value = temp_a;
    temp_b = stack_b->top->value;
    stack_b->top->value = stack_b->top->next->value;
    stack_b->top->next->value = temp_b;
    ft_printf("ss\n");
}
