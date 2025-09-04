#include "../../includes/push_swap.h"

void rra(t_stack *stack)
{
    t_node *last;
    t_node *second_last;

    if (stack->size < 2)
        return;
    second_last = stack->top;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    last = second_last->next;
    last->next = stack->top;
    second_last->next = NULL;
    stack->top = last;
}

void rrb(t_stack *stack)
{
    t_node *last;
    t_node *second_last;

    if (stack->size < 2)
        return;
    second_last = stack->top;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    last = second_last->next;
    last->next = stack->top;
    second_last->next = NULL;
    stack->top = last;
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}