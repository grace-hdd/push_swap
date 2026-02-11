/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
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

void	free_split(char **split)
{
	int	j;

	if (!split)
		return ;
	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

int	process_split_number(char *str, int **numbers, int *k)
{
	long	num;

	if (!is_number(str))
		return (0);
	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	(*numbers)[*k] = (int)num;
	(*k)++;
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
