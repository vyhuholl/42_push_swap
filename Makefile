# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 15:31:07 by sghezn            #+#    #+#              #
#    Updated: 2020/01/07 20:36:58 by sghezn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME_CH := checker
NAME_PS := push_swap

SRC := error.c stack.c
SRC_CH := checker.c
SRC_PS := push_swap.c

OBJ := $(SRC:%.c=%.o)
OBJ_CH := $(SRC_CH:%.c=%.o)
OBJ_PS := $(SRC_PS:%.c=%.o)

INC := -I push_swap.h -I ./libft/libft.h
LIB := -lft -L ./libft/

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all:
	@make -C libft
	$(CC) $(CFLAGS) $(INC) $(LIB) -c $(SRC) $(SRC_CH) $(SRC_PS) $< -o $@
	$(NAME_CH) $(NAME_PS)

$(NAME_CH):
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ) $(OBJ_CH) -o $(NAME_CH)

$(NAME_PS):
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ) $(OBJ_PS) -o $(NAME_PS)

clean:
	@make -C libft clean
	/bin/rm -rf $(OBJ) $(OBJ_CH) $(OBJ_PS)

fclean: clean
	@make -C libft fclean
	/bin/rm -rf $(NAME_CH) $(NAME_PS)

re: fclean all
