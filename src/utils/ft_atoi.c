#include "../includes/push_swap.h"

int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
           str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
        i++;
    
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (result > (INT_MAX - (str[i] - '0')) / 10)
        {
            if (sign == 1)
                return (INT_MAX);
            else
                return (INT_MIN);
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return (result * sign);
}
