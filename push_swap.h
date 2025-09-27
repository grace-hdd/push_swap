#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int value;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *bottom;
	int size;
}	t_stack;

int parse_args(int ac, char **av, int **numbers, int *count);
int has_duplicates(int *arr, int size);
void print_error(void);
long ft_atol(const char *str);

#endif