# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 15:31:07 by sghezn            #+#    #+#              #
#    Updated: 2020/03/10 12:17:48 by sghezn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME_CH = checker
NAME_PS = push_swap

INC = -I ./libft/libft.h -L./libft -lft -I get_next_line.h -I push_swap.h 

SRC = error.c get_next_line.c operation.c sort.c stack.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME_CH) $(NAME_PS)

$(NAME_CH): $(OBJ)
	make -C libft
	gcc -Wall -Wextra -Werror $(OBJ) checker.c -o $(NAME_CH) $(INC)

$(NAME_PS): $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) ps_sort_small.c ps_sort.c ps_optimize.c push_swap.c -o $(NAME_PS) $(INC)

clean:
	make -C libft clean
	/bin/rm -rf $(OBJ) $(OBJ_CH) $(OBJ_PS)

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(NAME_CH) $(NAME_PS)

re: fclean all
