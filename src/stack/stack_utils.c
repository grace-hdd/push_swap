#include "../includes/push_swap.h"

int stack_size(t_stack *stack)
{
    return (stack->size);
}


void print_stack(t_stack *stack, char name)
{
    t_node *current;
    int i;
    
    if (!stack)
        return;
    ft_printf("Stack %c: [", name);
    current = stack->top;
    i = 0;
    while (i < stack->size)
    {
        ft_printf("%d", current->value);
        if (current->next)
            ft_printf(", ");
        current = current->next;
        i++;
    }
    ft_printf("]\n");
}