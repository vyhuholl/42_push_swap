/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:35:42 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/10 11:42:48 by sghezn           ###   ########.fr       */
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
** Stacks are stored in double-linked lists with indexing by size.
** Operations lists are also stored in s_stack structure.
*/

typedef struct		s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
	int				index;
}					t_stack;

/*
** Stack A, stack B and the operation list are stored in a s_game structure.
*/

typedef struct		s_game
{
	t_stack			*a_top;
	t_stack			*b_top;
	t_stack			*a_stack;
	t_stack			*b_stack;
	size_t			a_size;
	size_t			b_size;
	t_stack			*op_list_top;
	t_stack			*op_list_stack;
}					t_game;

int					ft_is_numeric(char *str);
int					ft_atoi_limit(char *nbr, int *res);
int					ft_check_duplicates(t_game *game, char *nbr);
int					ft_read_stack(t_game *game, int argc, char **argv);
void				ft_swap(int *a, int *b);
int					ft_partition(int **array, int low, int high);
void				ft_quicksort(int **array, int low, int high);
void				ft_index_util(t_game *game, int *temp, int argc);
int					ft_index(t_game *game, int argc);
void				ft_op_swap(t_game *game, int op);
void				ft_op_push_a(t_game *game);
void				ft_op_push_b(t_game *game);
void				ft_op_rotate(t_game *game, int op);
void				ft_op_reverse_rotate(t_game *game, int op);
void				ft_do_op(t_game *game, int op);
int					ft_is_sorted(t_stack *stack);
void				ft_del_top(t_stack **stack);
void				ft_del_stack(t_stack **stack);

int					ft_checker_read_op(char *line);
int					ft_checker_do_op(t_game *game, char *line);

void				ft_ps_do_op(t_game *game, int op);
int					ft_ps_three_numbers_case(t_stack *stack);
void				ft_ps_sort_small_a(t_game *game, int size);
void				ft_ps_sort_small_b(t_game *game, int size);
int					ft_ps_get_pivot(t_game *game, char stack, int size);
int					ft_ps_not_all_pushed(t_game *game, char stack,
					int size, int pivot);
void				ft_ps_push_rotate_a(t_game *game, int pivot,
					size_t *ra, size_t *pb);
void				ft_ps_push_rotate_b(t_game *game, int pivot,
					size_t *rb, size_t *pa);
void				ft_ps_rotate(t_game *game, char stack, size_t r);
void				ft_ps_quicksort_a(t_game *game, int size);
void				ft_ps_quicksort_b(t_game *game, int size);
void				ft_ps_op_remove(t_game *game,
					int op_1, int op_2, int skip);
void				ft_ps_op_replace_util(t_stack **temp, t_stack **ptr,
					int op_1, int op);
void				ft_ps_op_replace(t_game *game,
					int op_1, int op_2, int skip);
void				ft_ps_optimize(t_game *game);
void				ft_ps_print_op(int op);
void				ft_ps_print_res(t_stack *res);

#endif
