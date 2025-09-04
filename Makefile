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
INCLUDES = -I includes

SRCDIR = src
OBJDIR = obj
INCDIR = includes

SOURCES = main.c \
		  stack/stack_operations.c \
		  stack/stack_utils.c \
		  stack/stack_init.c \
		  operations/swap.c \
		  operations/push.c \
		  operations/rotate.c \
		  operations/reverse_rotate.c \
		  parsing/parsing_input.c \
		  parsing/validate_input.c \
		  utils/error_handling.c \
		  utils/print_operations.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test test1 test2 test3