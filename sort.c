/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:37:03 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/27 20:06:17 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to perform a quicksort.
*/

/*
** Utility function to swap two numbers.
*/

void	ft_swap(int *a, int *b)
{
	int	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
** A function to find a pivot element index.
*/

int		ft_partition(int **array, int **sort_by, int low, int high)
{
	int	pivot;
	int i;
	int j;

	pivot = (*sort_by)[high];
	i = low;
	j = 0;
	while (j < high)
	{
		if ((*sort_by)[j] < pivot)
			ft_swap(&((*array)[i++]), &((*array)[j]));
		j++;
	}
	ft_swap(&((*array)[i]), &((*array)[high]));
	return (i);
}

/*
** A function to quicksort an array by another array or by itself.
*/

void	ft_quicksort(int **array, int **sort_by, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = ft_partition(array, sort_by, low, high);
		ft_quicksort(array, sort_by, low, pivot - 1);
		ft_quicksort(array, sort_by, pivot + 1, high);
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
