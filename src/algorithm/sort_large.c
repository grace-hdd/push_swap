#include "../../includes/push_swap.h"

static int get_chunk_size(t_stack *stack)
{
    int size;

    size = stack->size;
    if (size <= 100)
        return (15);
    else if (size <= 200)
        return (25);
    else if (size <= 300)
        return (35);
    else if (size <= 400)
        return (45);
    else
        return (50);
}

static int find_best_number(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;
    int best_num;
    int best_pos;
    int pos;

    current = stack_a->top;
    best_num = current->value;
    best_pos = 0;
    pos = 0;
    while (current)
    {
        if (current->value < best_num)
        {
            best_num = current->value;
            best_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (best_pos);
}

static void push_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
    int pushed;
    int best_pos;

    pushed = 0;
    while (pushed < chunk_size && stack_a->size > 3)
    {
        best_pos = find_best_number(stack_a, stack_b);
        if (best_pos <= stack_a->size / 2)
        {
            while (best_pos-- > 0)
                ra(stack_a);
        }
        else
        {
            while (best_pos++ < stack_a->size)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        pushed++;
    }
}

static void push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
    int best_pos;

    while (stack_b->size > 0)
    {
        best_pos = find_best_number(stack_a, stack_b);
        if (best_pos <= stack_a->size / 2)
        {
            while (best_pos-- > 0)
                ra(stack_a);
        }
        else
        {
            while (best_pos++ < stack_a->size)
                rra(stack_a);
        }
        pa(stack_a, stack_b);
    }
}

void sort_large(t_stack *stack_a, t_stack *stack_b)
{
    int chunk_size;

    if (is_sorted(stack_a))
        return;
    chunk_size = get_chunk_size(stack_a);
    push_to_b(stack_a, stack_b, chunk_size);
    sort_three(stack_a);
    push_back_to_a(stack_a, stack_b);
}