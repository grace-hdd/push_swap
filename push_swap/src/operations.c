/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:30:06 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/09 14:30:09 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_a(int *stack_a, int size_a) {
    if (size_a < 2) return;
    swap(&stack_a[0], &stack_a[1]);
}

void swap_b(int *stack_b, int size_b) {
    if (size_b < 2) return;
    swap(&stack_b[0], &stack_b[1]);
}

void swap_ab(int *stack_a, int size_a, int *stack_b, int size_b) {
    swap_a(stack_a, size_a);
    swap_b(stack_b, size_b);
}

void rotate(int *stack, int size) {
    if (size < 2) return;
    int temp = stack[0];
    for (int i = 0; i < size - 1; i++) {
        stack[i] = stack[i + 1];
    }
    stack[size - 1] = temp;
}

void rotate_a(int *stack_a, int size_a) {
    rotate(stack_a, size_a);
}

void rotate_b(int *stack_b, int size_b) {
    rotate(stack_b, size_b);
}

void rotate_ab(int *stack_a, int size_a, int *stack_b, int size_b) {
    rotate_a(stack_a, size_a);
    rotate_b(stack_b, size_b);
}

void reverse_rotate(int *stack, int size) {
    if (size < 2) return;
    int temp = stack[size - 1];
    for (int i = size - 1; i > 0; i--) {
        stack[i] = stack[i - 1];
    }
    stack[0] = temp;
}

void reverse_rotate_a(int *stack_a, int size_a) {
    reverse_rotate(stack_a, size_a);
}

void reverse_rotate_b(int *stack_b, int size_b) {
    reverse_rotate(stack_b, size_b);
}

void reverse_rotate_ab(int *stack_a, int size_a, int *stack_b, int size_b) {
    reverse_rotate_a(stack_a, size_a);
    reverse_rotate_b(stack_b, size_b);
}