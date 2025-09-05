#include "../../includes/push_swap.h"

static int find_min(t_stack *stack)
{
    t_node *current;
    int min;
    int min_pos;
    int pos;

    current = stack->top;
    min = current->value;
    min_pos = 0;
    pos = 0;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (min_pos);
}

static void push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int min_pos;
    int size;

    min_pos = find_min(stack_a);
    size = stack_a->size;
    if (min_pos <= size / 2)
    {
        while (min_pos-- > 0)
            ra(stack_a);
    }
    else
    {
        while (min_pos++ < size)
            rra(stack_a);
    }
    pb(stack_a, stack_b);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return;
    push_min_to_b(stack_a, stack_b);
    if (stack_a->size > 3)
        push_min_to_b(stack_a, stack_b);
    sort_three(stack_a);
    while (stack_b->size > 0)
        pa(stack_a, stack_b);
}
