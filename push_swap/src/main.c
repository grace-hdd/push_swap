/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:30:21 by grhaddad          #+#    #+#             */
/*   Updated: 2025/09/09 14:32:54 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/push_swap.h"

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Initialize stacks and process input arguments
	t_stack *stack_a = init_stack();
	t_stack *stack_b = init_stack();
	if (!stack_a || !stack_b) {
		ft_printf(stderr, "Error: Stack initialization failed.\n");
		return EXIT_FAILURE;
	}
	if (!parse_input(argc, argv, stack_a)) {
		fprintf(stderr, "Error: Invalid input.\n");
		free_stack(stack_a);
		free_stack(stack_b);
		return EXIT_FAILURE;
	}
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (EXIT_SUCCESS);
}