#include "../includes/push_swap.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] == 's')
        {
            char *str = va_arg(args, char *);
            if (str)
            {
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == 'c')
        {
            char c = va_arg(args, int);
            write(1, &c, 1);
            count++;
            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == 'd')
        {
            int num = va_arg(args, int);
            char buffer[12];
            int len = 0;
            int temp = num;
            
            if (num == 0)
            {
                write(1, "0", 1);
                count++;
            }
            else
            {
                if (num < 0)
                {
                    write(1, "-", 1);
                    count++;
                    num = -num;
                }
                while (temp > 0)
                {
                    buffer[len] = (temp % 10) + '0';
                    temp /= 10;
                    len++;
                }
                while (len > 0)
                {
                    write(1, &buffer[len - 1], 1);
                    len--;
                    count++;
                }
            }
            i += 2;
        }
        else
        {
            write(1, &format[i], 1);
            count++;
            i++;
        }
    }
    va_end(args);
    return (count);
}
