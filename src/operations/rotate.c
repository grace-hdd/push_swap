#include "../includes/push_swap.h"

void ra(t_stack *stack)
{
    t_node *current;
    t_node *last;
    t_node *old_top;

    if (stack->size < 2)
        return;
    current = stack->top;
    while (current->next != NULL)
        current = current->next;
    last = current;
    old_top = stack->top;
    stack->top = stack->top->next;
    old_top->next = NULL;
    last->next = old_top;
    ft_printf("ra\n");
}

void rb(t_stack *stack)
{
    t_node *current;
    t_node *last;
    t_node *old_top;

    if (stack->size < 2)
        return;
    current = stack->top;
    while (current->next != NULL)
        current = current->next;
    last = current;
    old_top = stack->top;
    stack->top = stack->top->next;
    old_top->next = NULL;
    last->next = old_top;
    ft_printf("rb\n");
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current_a;
    t_node *last_a;
    t_node *old_top_a;
    t_node *current_b;
    t_node *last_b;
    t_node *old_top_b;

    if (stack_a->size < 2 || stack_b->size < 2)
        return;
    current_a = stack_a->top;
    while (current_a->next != NULL)
        current_a = current_a->next;
    last_a = current_a;
    old_top_a = stack_a->top;
    stack_a->top = stack_a->top->next;
    old_top_a->next = NULL;
    last_a->next = old_top_a;
    current_b = stack_b->top;
    while (current_b->next != NULL)
        current_b = current_b->next;
    last_b = current_b;
    old_top_b = stack_b->top;
    stack_b->top = stack_b->top->next;
    old_top_b->next = NULL;
    last_b->next = old_top_b;
    ft_printf("rr\n");
}
