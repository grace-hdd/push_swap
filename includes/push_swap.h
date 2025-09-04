#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

int		push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
int		is_empty(t_stack *stack);
int		stack_size(t_stack *stack);
void	print_stack(t_stack *stack, char name);
t_stack	*create_stack(void);
void	destroy_stack(t_stack *stack);
t_stack	*init_stack_a(int argc, char **argv);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

int		*parse_input(int argc, char **argv, int *count);
int		validate_input(int *numbers, int count);

void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		get_position(t_stack *stack, int value);
int		get_median(t_stack *stack);
int		get_value_at_position(t_stack *stack, int position);
int		count_operations_to_top(t_stack *stack, int value);

int		get_optimal_chunk_size(int stack_size);
void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int median, int chunk_size);
int		find_best_rotation(t_stack *stack, int median);
void	execute_rotations(t_stack *stack, int operations);
void	sort_stack_b(t_stack *stack_a, t_stack *stack_b);

void	print_error(void);
void	cleanup_and_exit(t_stack *stack_a, t_stack *stack_b);
int		validate_stack(t_stack *stack);
void	print_operation(const char *operation);
void	print_operations_list(char **operations, int count);

#endif