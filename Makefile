# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:47:15 by dsiroten          #+#    #+#              #
#    Updated: 2024/05/03 12:49:40 by dsiroten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = base_cases_part_one.c	get_pivots.c push.c	reverse_rotate.c  simple_sort_five.c \
base_cases_part_two.c main.c   push_swap.c  rotate.c   sort_chunks.c sort_chunks_utils.c\
free_and_exit.c  optimize_commands.c  push_swap_utils.c  simple_sort.c  swap.c
OBJ = $(SRC:.c=.o)
HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBDIR = lib
LIB = $(LIBDIR)/lib.a

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB):
	@make -C $(LIBDIR)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBDIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re
