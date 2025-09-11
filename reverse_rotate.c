/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:58 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/11 12:44:47 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data, int print)
{
	int	temp;
	int	i;

	if (!data || !data->a || data->a->size < 2)
		return ;
	temp = data->a->array[data->a->size - 1];
	i = data->a->size - 1;
	while (i > 0)
	{
		data->a->array[i] = data->a->array[i - 1];
		i--;
	}
	data->a->array[0] = temp;
	if (print)
		ft_printf("rra\n");
	data->total_moves++;
}

void	rrb(t_data *data, int print)
{
	int	temp;
	int	i;

	if (!data || !data->b || data->b->size < 2)
		return ;
	temp = data->b->array[data->b->size - 1];
	i = data->b->size - 1;
	while (i > 0)
	{
		data->b->array[i] = data->b->array[i - 1];
		i--;
	}
	data->b->array[0] = temp;
	if (print)
		ft_printf("rrb\n");
	data->total_moves++;
}

void	rrr(t_data *data, int print)
{
	rra(data, 0);
	rrb(data, 0);
	if (print)
		ft_printf("rrr\n");
	data->total_moves -= 1;
}
