/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:40:10 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/11 12:44:24 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, int print)
{
	int	temp;
	int	i;

	if (!data || !data->a || data->a->size < 2)
		return ;
	temp = data->a->array[0];
	i = 0;
	while (i < data->a->size - 1)
	{
		data->a->array[1] = data->a->array[i + 1];
		i++;
	}
	data->a->array[data->a->size - 1] = temp;
	if (print)
		ft_printf("ra\n");
	data->total_moves++;
}

void	rb(t_data *data, int print)
{
	int	temp;
	int	i;

	if (!data || !data->b || data->b->size < 2)
		return ;
	temp = data->b->array[0];
	i = 0;
	while (i < data->b->size - 1)
	{
		data->b->array[i] = data->b->array[i + 1];
		i++;
	}
	data->b->array[data->b->size - 1] = temp;
	if (print)
		ft_printf("rb\n");
	data->total_moves++;
}

void	rr(t_data *data, int print)
{
	ra(data, 0);
	rb(data, 0);
	if (print)
		ft_printf("rr\n");
	data->total_moves -= 1;
}
