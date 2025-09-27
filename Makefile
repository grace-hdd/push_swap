NAME= push_swap
CC= cc
CFLAGS= -Wall -Wextra -Werror

SRC= main.c error.c parsing.c utils.c

OBJS= $(SRC:.c=.o)

LIBFT= ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re