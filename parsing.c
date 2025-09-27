#include "push_swap.h"

static int is_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

long ft_atol(const char *str)
{
	long sign;
	long result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int parse_args(int ac, char **av)
{
	char **split;
	int i;
	int j;
	int count;

	count = 0;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j]);
		{
			count++;
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (count);
}
