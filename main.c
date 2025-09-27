#include "push_swap.h"

int main(int argc, char **argv)
{
    int *numbers;
    int count;

    if (argc < 2)
        return (0);
    if (!parse_args(argc, argv, &numbers, &count))
    {
        print_error();
        return (1);
    }

    // ✅ At this point, numbers[] contains valid integers
    // and count = number of integers

    free(numbers);
    return (0);
}

