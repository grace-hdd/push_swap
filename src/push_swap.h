/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
}	t_data;

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
t_stack	*create_node(int value);
void	add_node_front(t_stack **stack, t_stack *new_node);
void	add_node_back(t_stack **stack, t_stack *new_node);
void	remove_node_front(t_stack **stack);
void	free_stack(t_stack **stack);
int		parse_arguments(int argc, char **argv, t_data *data);
int		parse_string_argument(char *str, t_data *data);
int		validate_number(char *str);
int		check_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	error_exit(t_data *data);
void	print_operation(char *op);
void	free_string_array(char **array);
void	sort_three(t_data *data);
void	sort_five(t_data *data);
void	sort_large(t_data *data);
void	assign_indexes(t_stack *stack);
int		find_min_position(t_stack *stack);
int		find_max_position(t_stack *stack);
void	move_to_top_a(t_data *data, int position);
void	move_to_top_b(t_data *data, int position);
void	push_chunk_to_b(t_data *data, int start, int end);
void	find_and_push_max(t_data *data);

#endif
