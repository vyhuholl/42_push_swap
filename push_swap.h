/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:35:42 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/07 21:37:35 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Stacks are stored in double-linked lists with indexing.
*/

typedef struct	s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
	int				index;
}				t_stack;

/*
** Stacks A and B are stored in a s_game structure.
*/

typedef struct	s_game
{
	t_stack	*a_top;
	t_stack	*b_top;
	t_stack	*a_stack;
	t_stack	*b_stack;
	size_t	a_size;
	size_t	b_size;
}				t_game;

int	ft_is_numeric(char *str);
int	ft_atoi_limit(t_game *game, char *nbr, int *res);
int	ft_check_duplicates(t_game *game, char *nbr);
int	ft_read_stack(t_game *game, int argc, char **argv);

#endif
