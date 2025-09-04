#include "../../includes/push_swap.h"

int push(t_stack *stack, int value)
{
    t_node *node;
    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->value = value;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    return (1);
}

int pop(t_stack *stack)
{
    int value;
    t_node *ptr;

    if (is_empty(stack))
        return (0);
    value = stack->top->value;
    ptr = stack->top;
    stack->top = stack->top->next;
    free(ptr);
    stack->size--;
    return (value);
}

int peek(t_stack *stack)
{
        if (is_empty(stack))
            return (0);
        return (stack->top->value);
}

int is_empty(t_stack *stack)
{
    return (stack->top == NULL);
}