#include "../includes/push_swap.h"

t_stack *create_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

t_stack *init_stack_a(int argc, char **argv)
{
    int *numbers;
    int count;
    t_stack *stack;
    int i;

    numbers = parse_input(argc, argv, &count);
    if (!numbers)
        return (NULL);
    if (!validate_input(numbers, count))
    {
        free(numbers);
        return (NULL);
    }
    stack = create_stack();
    i = 0;
    while (i < count)
    {
        if (!push(stack, numbers[i]))
        {
            free(numbers);
            destroy_stack(stack);
            return (NULL);
        }
        i++;
    }
    free(numbers);
    return (stack);

}