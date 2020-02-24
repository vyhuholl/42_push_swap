/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:08:47 by sghezn            #+#    #+#             */
/*   Updated: 2020/02/25 02:20:53 by sghezn           ###   ########.fr       */
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
		elem->val = op;
		elem->prev = game->op_list_stack;
		game->op_list_stack->next = elem;
		game->op_list_stack = elem;
	}
}

/*
** A function to quicksort stack A.
**.
Resulting operations list is written to op_list_stack.
*/

void	ft_ps_quicksort(t_game *game, char stack, int size, int deep)
{
	int	pivot;

	if (size <= 3)
		if (stack == 'a')
			ft_ps_sort_small_a(game, size);
		else
			ft_ps_sort_small_b(game, size);
	else
	{
		if (stack == 'a')
		{
			pivot = ft_ps_partition_a(game, size, deep, -1);
			ft_ps_quicksort(game, pivot, 'a', deep + 1);
			ft_ps_quicksort(game, size - pivot, 'b', deep + 1);
		}
		else
		{
			pivot = ft_ps_partition_b(game, size);
			ft_ps_quicksort(game, size - pivot, 'a', deep + 1);
			ft_ps_quicksort(game, pivot, 'b', deep + 1);
		}
	}
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
	if (!ft_read_stack(&game, argc, argv) || !ft_index(&game, argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ft_is_sorted(game.a_top))
		return (0);
	ft_ps_quicksort(&game, 'a', game.a_size, 0);
	ft_ps_print_res(game.op_list_stack);
	ft_del_stack(&game.op_list_stack);
	return (0);
}
