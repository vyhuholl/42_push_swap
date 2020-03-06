/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:22:38 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/06 14:00:09 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_push_rotate_a(t_game *game, int pivot, int *ra, int *pb)
{
	
}

void	ft_ps_push_rotate_b(t_game *game, int pivot, int *rb, int *pa)
{
	
}

/*
** A function to quicksort stack A.
** Resulting operations list is written to op_list_stack.
*/

void	ft_ps_quicksort_a(t_game *game, int size)
{
	int	pivot;
	int	ra;
	int	pb;
	int	i;

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
	}
}

/*
** A function to quicksort stack B.
** Resulting operations list is written to op_list_stack.
*/

void	ft_ps_quicksort_b(t_game *game, int size)
{
	int	pivot;
	int	rb;
	int	pa;
	int	i;

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
	}
}
