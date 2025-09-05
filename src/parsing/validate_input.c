#include "../includes/push_swap.h"

static int check_duplicates(int *numbers, int count)
{
    int i;
    int j;

    i = 0;
    while (i < count)
    {
        j = i + 1;
        while (j < count)
        {
            if (numbers[i] == numbers[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

static int check_limits(int *numbers, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        if (numbers[i] > INT_MAX || numbers[i] < INT_MIN)
            return (0);
        i++;
    }
    return (1);
}

int validate_input(int *numbers, int count)
{
    if (!check_duplicates(numbers, count))
        return (0);
    if (!check_limits(numbers, count))
        return (0);
    return (1);
}
