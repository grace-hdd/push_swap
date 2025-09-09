/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:30:14 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/09 14:31:13 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_stack
{
    int *data;
    int top;
    int size;
} t_stack;

void    init_stack(t_stack *stack, int size);
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
int     is_empty(t_stack *stack);
void    swap(t_stack *stack);
void    rotate(t_stack *stack);
void    reverse_rotate(t_stack *stack);
void    sort_stack(t_stack *stack_a, t_stack *stack_b);
void    free_stack(t_stack *stack);
void    error(const char *message);
int     validate_input(int argc, char **argv);
void    print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif /* PUSH_SWAP_H */