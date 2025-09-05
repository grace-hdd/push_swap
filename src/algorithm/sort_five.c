#include "../../includes/push_swap.h"

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int min;
    int i;

    if (is_sorted(stack_a))
        return;
    i = 0;
    while (i < 2)
    {
        min = find_min(stack_a);
        while (stack_a->top->value != min)
        {
            if (get_position(stack_a, min) <= stack_a->size / 2)
                ra(stack_a);
            else
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        i++;
    }
    sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}
