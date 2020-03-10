/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:08:47 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/10 12:48:05 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** A program to find the smallest list of operations to sort a given stack.
*/

/*
** A function to execute an operation and write it to the operations list.
*/

void	ft_ps_do_op(t_game *game, int op)
{
	t_stack	*elem;

	ft_do_op(game, op);
	if (!(game->op_list_top))
	{
		game->op_list_top = ft_memalloc(sizeof(t_stack));
		game->op_list_top->value = op;
		game->op_list_stack = game->op_list_top;
	}
	else
	{
		elem = ft_memalloc(sizeof(t_stack));
		elem->value = op;
		elem->prev = game->op_list_stack;
		game->op_list_stack->next = elem;
		game->op_list_stack = elem;
	}
}

void	ft_ps_optimize(t_game *game)
{
	ft_ps_op_remove(game, SA, SA, RB);
	ft_ps_op_remove(game, SB, SB, RA);
	ft_ps_op_remove(game, SA, SA, RRB);
	ft_ps_op_remove(game, SB, SB, RRA);
	ft_ps_op_remove(game, RA, RRA, SB);
	ft_ps_op_remove(game, RB, RRB, SA);
	ft_ps_op_remove(game, RRA, RA, SB);
	ft_ps_op_remove(game, RRB, RB, SA);
	ft_ps_op_remove(game, PA, PB, 0);
	ft_ps_op_remove(game, PB, PA, 0);
	ft_ps_op_replace(game, SA, SB, RA);
	ft_ps_op_replace(game, SB, SA, RB);
	ft_ps_op_replace(game, SA, SB, RRA);
	ft_ps_op_replace(game, SB, SA, RRB);
	ft_ps_op_replace(game, RA, RB, SA);
	ft_ps_op_replace(game, RB, RA, SB);
	ft_ps_op_replace(game, RRA, RRB, SA);
	ft_ps_op_replace(game, RRB, RRA, SB);
}

/*
** A function to print a single operation.
*/

void	ft_ps_print_op(int op)
{
	if (op == 1)
		ft_putstr("sa\n");
	else if (op == 2)
		ft_putstr("sb\n");
	else if (op == 3)
		ft_putstr("ss\n");
	else if (op == 4)
		ft_putstr("pa\n");
	else if (op == 5)
		ft_putstr("pb\n");
	else if (op == 6)
		ft_putstr("ra\n");
	else if (op == 7)
		ft_putstr("rb\n");
	else if (op == 8)
		ft_putstr("rr\n");
	else if (op == 9)
		ft_putstr("rra\n");
	else if (op == 10)
		ft_putstr("rrb\n");
	else if (op == 11)
		ft_putstr("rrr\n");
}

/*
** A function to print a list of operations.
*/

void	ft_ps_print_res(t_stack *res)
{
	t_stack	*ptr;

	ptr = res;
	while (ptr)
	{
		ft_ps_print_op(ptr->value);
		ptr = ptr->next;
	}
}

/*
** The main push_swap function.
*/

int		main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (0);
	ft_bzero(&game, sizeof(game));
	if (ft_read_stack(&game, argc, argv) == -1 || ft_index(&game, argc) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ft_is_sorted(game.a_top))
		return (0);
	ft_ps_quicksort_a(&game, game.a_size);
	ft_ps_optimize(&game);
	ft_ps_print_res(game.op_list_stack);
	ft_del_stack(&game.op_list_stack);
	return (0);
}
