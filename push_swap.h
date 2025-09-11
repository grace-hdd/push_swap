/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:05:16 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/11 12:50:29 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		total_moves;
}	t_data;

t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
void	push_stack(t_stack *stack, int value);
int		pop_stack(t_stack *stack);
int		peek_stack(t_stack *stack, int index);
int		is_empty(t_stack *stack);

void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);
void	pa(t_data *data, int print);
void	pb(t_data *data, int print);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);

int		parse_arguments(int argc, char **argv, t_stack *stack);
int		is_valid_integer(char *str);
long	ft_atol(char *str);
int		has_duplicates(t_stack *stack);
char	**ft_split(char const *s, char c);
void	free_split(char **split);

void	sort_stack(t_data *data);
void	sort_three(t_data *data);
void	sort_small(t_data *data);
void	radix_sort(t_data *data);
int		get_max_bits(t_stack *stack);

int		is_sorted(t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
void	normalize_stack(t_stack *stack);
void	print_error(void);

void	print_stacks(t_data *data);

#endif