/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:22:38 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/10 11:41:41 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_push_rotate_a(t_game *game, int pivot, size_t *ra, size_t *pb)
{
	if (game->a_top->value < pivot)
	{
		ft_ps_do_op(game, PB);
		(*pb)++;
	}
	else
	{
		ft_ps_do_op(game, RA);
		(*ra)++;
	}
}

void	ft_ps_push_rotate_b(t_game *game, int pivot, size_t *rb, size_t *pa)
{
	if (game->b_top->value > pivot)
	{
		ft_ps_do_op(game, PA);
		(*pa)++;
	}
	else
	{
		ft_ps_do_op(game, RB);
		(*rb)++;
	}
}

void	ft_ps_rotate(t_game *game, char stack, size_t r)
{
	if (stack == 'a')
	{
		if (r > game->a_size / 2)
			while (game->a_size - r++)
				ft_ps_do_op(game, RA);
		else
			while (r--)
				ft_ps_do_op(game, RRA);
	}
	else
	{
		if (r > game->b_size / 2)
			while (game->b_size - r++)
				ft_ps_do_op(game, RB);
		else
			while (r--)
				ft_ps_do_op(game, RRB);
	}
}

/*
** A function to quicksort stack A.
** Resulting operations list is written to op_list_stack.
*/

void	ft_ps_quicksort_a(t_game *game, int size)
{
	int		pivot;
	size_t	ra;
	size_t	pb;
	int		i;

	if (size <= 3)
		ft_ps_sort_small_a(game, size);
	else
	{
		ra = 0;
		pb = 0;
		i = 0;
		pivot = ft_ps_get_pivot(game, 'a', size);
		while (ft_ps_not_all_pushed(game, 'a', size - i, pivot) && i++ < size)
			ft_ps_push_rotate_a(game, pivot, &ra, &pb);
		ft_ps_rotate(game, 'a', ra);
		ft_ps_quicksort_a(game, size - pb);
		ft_ps_quicksort_b(game, pb);
		while (game->b_top && pb--)
			ft_ps_do_op(game, PA);
	}
}

/*
** A function to quicksort stack B.
** Resulting operations list is written to op_list_stack.
*/

void	ft_ps_quicksort_b(t_game *game, int size)
{
	int		pivot;
	size_t	rb;
	size_t	pa;
	int		i;

	if (size <= 3)
		ft_ps_sort_small_b(game, size);
	else
	{
		rb = 0;
		pa = 0;
		i = 0;
		pivot = ft_ps_get_pivot(game, 'b', size);
		while (ft_ps_not_all_pushed(game, 'b', size - i, pivot) && i++ < size)
			ft_ps_push_rotate_b(game, pivot, &rb, &pa);
		ft_ps_rotate(game, 'b', rb);
		ft_ps_quicksort_a(game, pa);
		ft_ps_quicksort_b(game, size - pa);
		while (game->a_top && pa--)
			ft_ps_do_op(game, PB);
	}
}
