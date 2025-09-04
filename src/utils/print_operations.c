#include "../includes/push_swap.h"

void print_operation(const char *operation)
{
    ft_printf("%s\n", operation);
}

void print_operations_list(char **operations, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        ft_printf("%s\n", operations[i]);
        i++;
    }
}

