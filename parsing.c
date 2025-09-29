/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (!str || !*str)
		return (0);
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

static void	free_and_count(char **split, int *count)
{
	int	j;

	j = 0;
	while (split[j])
	{
		(*count)++;
		j++;
	}
	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

static int	count_numbers(int ac, char **av)
{
	char	**split;
	int		i;
	int		count;

	count = 0;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		free_and_count(split, &count);
		i++;
	}
	return (count);
}

static int	process_argument(char *arg, int **numbers, int *k)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!process_split_number(split[j], numbers, k))
		{
			free_split(split);
			return (0);
		}
		j++;
	}
	free_split(split);
	return (1);
}

int	parse_args(int ac, char **av, int **numbers, int *count)
{
	int		i;
	int		k;

	*count = count_numbers(ac, av);
	if (*count <= 0)
		return (0);
	*numbers = malloc(sizeof(int) * (*count));
	if (!*numbers)
		return (0);
	k = 0;
	i = 1;
	while (i < ac)
	{
		if (!process_argument(av[i], numbers, &k))
			return (0);
		i++;
	}
	if (has_duplicates(*numbers, *count))
		return (0);
	return (1);
}
