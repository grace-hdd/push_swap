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

static void rotate_single(t_stack *stack)
{
    t_node *current;
    t_node *last;
    t_node *old_top;

    current = stack->top;
    while (current->next != NULL)
        current = current->next;
    last = current;
    old_top = stack->top;
    stack->top = stack->top->next;
    old_top->next = NULL;
    last->next = old_top;
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size < 2 || stack_b->size < 2)
        return;
    rotate_single(stack_a);
    rotate_single(stack_b);
    ft_printf("rr\n");
}
