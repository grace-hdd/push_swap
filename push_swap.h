/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/10/04 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/* Parsing and validation */
int		parse_args(int ac, char **av, int **numbers, int *count);
int		has_duplicates(int *arr, int size);
int		is_sorted(t_stack *stack);
void	print_error(void);
long	ft_atol(const char *str);
void	free_split(char **split);
int		process_split_number(char *str, int **numbers, int *k);
int		is_number(char *str);

/* Stack operations */
t_stack	*init_stack(void);
t_node	*create_node(int value);
void	push_bottom(t_stack *stack, t_node *new_node);
void	push_top(t_stack *stack, t_node *new_node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
void	free_stack(t_stack *stack);

/* Push operations */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/* Swap operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* Rotate operations */
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

/* Reverse rotate operations */
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Sorting algorithms */
void	sort_small(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	sort_turk(t_stack *a, t_stack *b);
int		get_min_pos(t_stack *stack);
int		get_max_pos(t_stack *stack);
void	rotate_to_pos(t_stack *stack, int pos);
void	rotate_to_pos_b(t_stack *stack, int pos);
void	push_min_to_b(t_stack *a, t_stack *b, int *size);

/* Sort helpers */
void	push_half_to_b(t_stack *a, t_stack *b);
void	push_all_but_three(t_stack *a, t_stack *b);
void	shift_stack(t_stack *stack, char stack_name);
void	rotate_to_min(t_stack *stack, char stack_name, int lowest_pos);
void	reverse_rotate_to_min(t_stack *stack, char stack_name,
			int lowest_pos, int stack_size);

/* Cost calculation and optimization */
void	get_target_position(t_stack *a, t_stack *b);
int		get_target_pos(t_stack *a, int b_value);
void	get_cost(t_stack *a, t_stack *b);
void	do_cheapest_move(t_stack *a, t_stack *b);
void	do_move(t_stack *a, t_stack *b, int cost_a, int cost_b);
void	do_rr(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void	do_rrr(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void	do_ra_rra(t_stack *a, int cost);
void	do_rb_rrb(t_stack *b, int cost);
int		abs(int x);

/* Utils */
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	push_swap(t_stack *a, t_stack *b);

#endif