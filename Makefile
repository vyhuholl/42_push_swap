# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 15:31:07 by sghezn            #+#    #+#              #
#    Updated: 2020/03/10 10:45:47 by sghezn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME_CH := checker
NAME_PS := push_swap

SRC := error.c get_next_line.c operation.c sort.c stack.c
SRC_CH := checker.c
SRC_PS := ps_sort_small.c ps_sort.c ps_optimize.c push_swap.c

OBJ := $(SRC:%.c=%.o)
OBJ_CH := $(SRC_CH:%.c=%.o)
OBJ_PS := $(SRC_PS:%.c=%.o)

INC := -I push_swap.h -I get_next_line.h -I ./libft/libft.h

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all:
	@make -C libft
	$(CC) $(CFLAGS) $(INC) -c $(SRC) $(SRC_CH) $(SRC_PS)
	$(NAME_CH) $(NAME_PS)

$(NAME_CH):
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(OBJ_CH) -o $(NAME_CH)

$(NAME_PS):
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(OBJ_PS) -o $(NAME_PS)

clean:
	@make -C libft clean
	/bin/rm -rf $(OBJ) $(OBJ_CH) $(OBJ_PS)

fclean: clean
	@make -C libft fclean
	/bin/rm -rf $(NAME_CH) $(NAME_PS)

re: fclean all
