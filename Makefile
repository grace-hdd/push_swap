# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by user              #+#    #+#              #
#    Updated: 2024/01/01 00:00:00 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.

SRCDIR = src
OBJDIR = obj

SOURCES = main.c \
		  operations/swap_operations.c \
		  operations/push_operations.c \
		  operations/rotate_operations.c \
		  operations/reverse_rotate_operations.c \
		  utils/stack_management.c \
		  utils/parsing.c \
		  utils/utilities.c \
		  sorting/sort_three.c \
		  sorting/sort_five.c \
		  sorting/sort_large.c \
		  sorting/helper_functions.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: libft $(NAME)

libft:
	@make -C ../libft

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJECTS) ../libft/libft.a

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
