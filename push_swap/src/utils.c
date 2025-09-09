/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:31:28 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/09 14:31:29 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../include/push_swap.h"

void    error_exit(const char *message)
{
    write(2, message, ft_strlen(message));
    exit(EXIT_FAILURE);
}

int     ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int     is_digit_string(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

void    free_stack(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}