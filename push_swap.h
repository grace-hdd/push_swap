/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42beirut.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:39:42 by grhaddad          #+#    #+#           */
/*   Updated: 2025/09/29 17:39:42 by grhaddad         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
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
void	rotate_to_pos(t_stack *stack, int pos);
void	push_min_to_b(t_stack *a, t_stack *b, int *size);

/* Utils */
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	push_swap(t_stack *a, t_stack *b);

#endif