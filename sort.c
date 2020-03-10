/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:37:03 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/10 11:30:06 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to perform a quicksort.
*/

void	ft_index_util(t_game *game, int *temp, int argc)
{
	t_stack	*ptr;
	int		i;

	ptr = game->a_top;
	while (ptr)
	{
		i = -1;
		while (++i < argc)
		{
			if (temp[i] == ptr->value)
			{
				ptr->index = i;
				break ;
			}
		}
		ptr = ptr->prev;
	}
}

/*
** Utility function to swap two numbers.
*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
** A function to find a pivot element index.
*/

int		ft_partition(int **array, int low, int high)
{
	int	pivot;
	int i;
	int j;

	pivot = (*array)[high];
	i = low;
	j = 0;
	while (j < high)
	{
		if ((*array)[j] < pivot)
			ft_swap(&((*array)[i++]), &((*array)[j]));
		j++;
	}
	ft_swap(&((*array)[i]), &((*array)[high]));
	return (i);
}

/*
** A function to quicksort an array.
*/

void	ft_quicksort(int **array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = ft_partition(array, low, high);
		ft_quicksort(array, low, pivot - 1);
		ft_quicksort(array, pivot + 1, high);
	}
}

/*
** A function to check whether a stack is sorted.
*/

int		ft_is_sorted(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr)
	{
		if (!ptr->prev)
			return (1);
		else if (ptr->prev->value < ptr->value)
			return (0);
		ptr = ptr->prev;
	}
	return (1);
}
