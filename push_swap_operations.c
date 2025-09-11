/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:31:04 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/11 12:39:55 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int print)
{
	int	temp;

	if (!data || !data->a || data->a->size < 2)
		return ;
	temp = data->a->array[0];
	data->a->array[0] = data->a->array[1];
	data->a->array[1] = temp;
	if (print)
		ft_printf("sa\n");
	data->total_moves++;
}

void	sb(t_data *data, int print)
{
	int	temp;

	if (!data || !data->b || data->b->size < 2)
		return ;
	temp = data->b->array[0];
	data->b->array[0] = data->b->array[1];
	data->b->array[1] = temp;
	if (print)
		ft_printf("sb\n");
	data->total_moves++;
}

void	ss(t_data *data, int print)
{
	sa(data, 0);
	sb(data, 0);
	if (print)
		ft_printf("ss\n");
	data->total_moves -= 1;
}

void	pa(t_data *data, int print)
{
	int	value;

	if (!data || is_empty(data->b))
		return ;
	value = pop_stack(data->b);
	push_stack(data->a, value);
	if (print)
		ft_printf("pa\n");
	data->total_moves++;
}

void	pb(t_data *data, int print)
{
	int	value;

	if (!data || is_empty(data->a))
		return ;
	value = pop_stack(data->a);
	push_stack(data->b, value);
	if (print)
		ft_printf("pb\n");
	data->total_moves++;
}
