/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:35:42 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/20 19:25:23 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# include "libft/libft.h"
# include "get_next_line.h"
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

int		ft_is_numeric(char *str);
int		ft_atoi_limit(t_game *game, char *nbr, int *res);
int		ft_check_duplicates(t_game *game, char *nbr);
int		ft_read_stack(t_game *game, int argc, char **argv);
void	ft_swap(int *a, int *b);
int		ft_partition(int **array, int **sort_by, int low, int high);
void	ft_quicksort(int **array, int **sort_by, int low, int high);
int		ft_index(t_game *game, int argc, char **argv);
void	ft_op_swap(t_game *game, int op);
void	ft_op_push_a(t_game *game, int op);
void	ft_op_push_b(t_game *game, int op);
void	ft_op_rotate(t_game *game, int op);
void	ft_op_reverse_rotate(t_game *game, int op);
void	ft_do_op(t_game *game, int op);
int		ft_is_sorted(t_stack *stack);

int		ft_checker_read_op(char *line);
int		ft_checker_do_op(t_game *game, char *line);

#endif
