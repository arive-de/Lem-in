# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arive-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/26 14:26:51 by arive-de          #+#    #+#              #
#    Updated: 2017/09/12 16:18:42 by arive-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= lem-in

SRC= ./srcs/lem_in.c \
	 ./srcs/parser.c \
	 ./srcs/list.c \
	 ./srcs/list_tub.c \
	 ./srcs/list_queue.c \
	 ./srcs/list_output.c \
	 ./srcs/parser2.c \
	 ./srcs/checker.c \
	 ./srcs/init_solver.c \
	 ./srcs/solver.c \
	 ./srcs/print.c

OBJ= $(subst .c,.o, $(SRC))

CC= gcc

CFLAGS= -Wall -Wextra -Werror

HEAD= -I libft/ -I include

LIBFT= ./libft/libft.a

%.o: %.c
	@$(CC) $(CFLAGS) $(HEAD) -o $@ -c $<

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(HEAD) -o $(NAME) $(LIBFT) $(OBJ)

$(LIBFT):
	@make -C libft
	@echo "Compiled"

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft clean
	@echo "Cleaned"

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf ./libft/libft.a
	@echo "Fleaned"

re: fclean all
