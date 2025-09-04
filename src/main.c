#include "../../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;

    if (argc < 2)
    {
        ft_printf("Error\n");
        return (1);
    }
    stack_a = init_stack_a(argc, argv);
    if (!stack_a)
    {
        ft_printf("Error\n");
        return (1);
    }
    print_stack(stack_a, 'A');
    destroy_stack(stack_a);
    return (0);
}