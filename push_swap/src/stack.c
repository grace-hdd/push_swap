/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:30:49 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/09 14:30:57 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *create_stack(int capacity)
{
    t_stack *stack = malloc(sizeof(t_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = malloc(stack->capacity * sizeof(int));
    return stack;
}

int is_empty(t_stack *stack)
{
    return stack->top == -1;
}

int is_full(t_stack *stack)
{
    return stack->top == stack->capacity - 1;
}

void push(t_stack *stack, int item)
{
    if (is_full(stack))
        return; // Stack overflow
    stack->data[++stack->top] = item;
}

int pop(t_stack *stack)
{
    if (is_empty(stack))
        return -1; // Stack underflow
    return stack->data[stack->top--];
}

int peek(t_stack *stack)
{
    if (is_empty(stack))
        return -1; // Stack is empty
    return stack->data[stack->top];
}

void free_stack(t_stack *stack)
{
    free(stack->data);
    free(stack);
}