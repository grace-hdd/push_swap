NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft
LIBFT = libft/libft.a

SRCDIR = src

SOURCES = src/main.c \
		  src/stack/stack_operations.c \
		  src/stack/stack_utils.c \
		  src/stack/stack_init.c \
		  src/operations/swap.c \
		  src/operations/push.c \
		  src/operations/rotate.c \
		  src/operations/reverse_rotate.c \
		  src/parsing/parsing_input.c \
		  src/parsing/validate_input.c \
		  src/utils/error_handling.c \
		  src/utils/print_operations.c \
		  src/algorithm/sort_small.c \
		  src/algorithm/sort_large.c \
		  src/algorithm/algorithm_utils.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re