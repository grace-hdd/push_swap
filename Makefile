NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	error.c \
	parsing.c \
	validation.c \
	utils.c \
	stack.c \
	stack_utils.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	sort_large.c \
	sort_utils.c \
	sort_small.c \
	helpers.c \
	cost.c \
	target.c

OBJS = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

HEADERS = push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re