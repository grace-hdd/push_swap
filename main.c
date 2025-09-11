/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:48:16 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/11 12:51:08 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*init_data(int size)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = init_stack(size);
	data->b = init_stack(size);
	if (!data->a || !data->b)
	{
		free_stack(data->a);
		free_stack(data->b);
		free(data);
		return (NULL);
	}
	data->total_moves = 0;
	return (data);
}

static void	free_data(t_data *data)
{
	if (data)
	{
		free_stack(data->a);
		free_stack(data->b);
		free(data);
	}
}

static int	count_total_numbers(int argc, char **argv)
{
	int		count;
	int		i;
	char	**split;

	count = 0;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (0);
		i = 0;
		while (split[i])
		{
			count++;
			i++;
		}
		free(split);
	}
	else
	{
		count = argc - 1;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		total_numbers;

	if (argc < 2)
		return (0);
	total_numbers = count_total_numbers(argc, argv);
	if (total_numbers == 0)
	{
		print_error();
		return (1);
	}
	data = init_data(total_numbers);
	if (!data)
	{
		print_error();
		return (1);
	}
	if (!parse_arguments(argc, argv, data->a))
	{
		print_error();
		free_data(data);
		return (1);
	}
	sort_stack(data);
	free_data(data);
	return (0);
}
