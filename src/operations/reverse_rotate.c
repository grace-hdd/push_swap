#include "../includes/push_swap.h"

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
    ft_printf("rra\n");
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
    ft_printf("rrb\n");
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    t_node *last_a;
    t_node *second_last_a;
    t_node *last_b;
    t_node *second_last_b;

    if (stack_a->size < 2 || stack_b->size < 2)
        return;
    second_last_a = stack_a->top;
    while (second_last_a->next->next != NULL)
        second_last_a = second_last_a->next;
    last_a = second_last_a->next;
    last_a->next = stack_a->top;
    second_last_a->next = NULL;
    stack_a->top = last_a;
    second_last_b = stack_b->top;
    while (second_last_b->next->next != NULL)
        second_last_b = second_last_b->next;
    last_b = second_last_b->next;
    last_b->next = stack_b->top;
    second_last_b->next = NULL;
    stack_b->top = last_b;
    ft_printf("rrr\n");
}