/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:22:38 by sghezn            #+#    #+#             */
/*   Updated: 2020/02/29 23:30:04 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** A function to quicksort stack A.
** Resulting operations list is written to op_list_stack.
*/

void	ft_ps_quicksort(t_game *game, int size)
{
	int	pivot;

	if (size <= 3)
		ft_ps_sort_small_a(game, size);
	else
	{
		pivot = ft_ps_get_pivot();
	}
}

/*
** A function to quicksort stack B.
** Resulting operations list is written to op_list_stack.
*/

void	ft_ps_quicksort_b(t_game *game, int size)
{
	int	pivot;

	if (size <= 3)
		ft_ps_sort_small_b(game, size);
}
