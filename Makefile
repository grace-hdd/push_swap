# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/12 10:30:25 by grhaddad          #+#    #+#              #
#    Updated: 2025/09/12 12:41:24 by grhaddad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT       = libft/libft.a
FT_PRINTF   = ft_printf/libftprintf.a

SRCS        = handle_errors.c init_a_to_b.c init_b_to_a.c main.c \
              push.c reverse_rotate.c rotate.c sort_stacks.c \
              sort_three.c split.c stack_init.c stack_utils.c swap.c

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	@make -C libft

$(FT_PRINTF):
	@make -C ft_printf

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C libft
	@make clean -C ft_printf

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@$(RM) $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
