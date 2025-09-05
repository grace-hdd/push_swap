#include "../../includes/push_swap.h"

int find_min(t_stack *stack)
{
    t_node *current;
    int min;

    current = stack->top;
    min = current->value;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int find_max(t_stack *stack)
{
    t_node *current;
    int max;

    current = stack->top;
    max = current->value;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int get_position(t_stack *stack, int value)
{
    t_node *current;
    int pos;

    current = stack->top;
    pos = 0;
    while (current)
    {
        if (current->value == value)
            return (pos);
        current = current->next;
        pos++;
    }
    return (-1);
}

int get_median(t_stack *stack)
{
    t_node *current;
    int sum;
    int count;

    current = stack->top;
    sum = 0;
    count = 0;
    while (current)
    {
        sum += current->value;
        count++;
        current = current->next;
    }
    return (sum / count);
}