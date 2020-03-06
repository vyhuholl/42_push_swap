/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:22:38 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/06 13:33:02 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ps_get_pivot(t_game *game, char stack, int size)
{
	t_stack	*ptr;
	int		*tab;
	int		len;
	int		res;

	ptr = (stack == 'a') ? game->a_top : game->b_top;
	res = 0;
	tab = (int*)malloc(sizeof(int) * size);
	if (tab)
	{
		len = 0;
		while (ptr && size--)
		{
			tab[len++] = ptr->val;
			ptr = ptr->prev;
		}
		ft_quicksort(&tab, &tab, 0, len - 1);
		res = tab[len / 2];
		free(size);
	}
	else
		return (-1);
	return (res);
}

/*
** A function to quicksort stack A.
** Resulting operations list is written to op_list_stack.
*/

void	ft_ps_quicksort_a(t_game *game, int size)
{
	int	pivot;

	if (size <= 3)
		ft_ps_sort_small_a(game, size);
	else
	{
		pivot = ft_ps_get_pivot(game, 'a', size);
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
	else
	{
		pivot = ft_ps_get_pivot(game, 'b', size);
	}
}
