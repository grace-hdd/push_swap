#include "../../includes/push_swap.h"

int *parse_input(int argc, char **argv, int *count)
{
    int *numbers;
    int i;

    if (argc < 2)
        return (NULL);
    *count = argc - 1;
    numbers = (int *)malloc(*count * sizeof(int));
    if (!numbers)
        return (NULL);
    i = 0;
    while (i < *count)
    {
        numbers[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    return (numbers);
}