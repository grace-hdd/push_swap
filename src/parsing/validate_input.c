#include "../../includes/push_swap.h"

int validate_input(int *numbers, int count)
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
    i = 0;
    while (i < count)
    {
        if (numbers[i] > INT_MAX || numbers[i] < INT_MIN)
            return (0);
        i++;
    }
    return (1);
}
