/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:18:49 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/09 16:54:08 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to perform operations with stacks.
*/

/*
** A function to sort the index of a stack (using quicksort).
** Returns -1 in case of a memory error.
*/

int	ft_index(t_game *game, int argc, char **argv)
{
	t_stack	*ptr;
	int		*temp;
	int		i;

	if (!(temp = (int*)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	i = 0;
	while (i < argc - 1)
		temp[i] = i++;
	ft_quicksort(&temp, argv, 0, argc - 2);
	ptr = game->a_top;
	while (ptr)
	{
		ptr->index = temp[--argc];
		ptr = ptr->prev;
	}
	free(temp);
	return (1);
}

/*
** A function to read input to stack A.
** Returns -1 in case of an error.
*/

int	ft_read_stack(t_game *game, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_numeric(argv[i]))
			return (-1);
		if (!game->a_stack)
		{
			if (!(game->a_stack = ft_memalloc(sizeof(t_stack))))
				return (-1);
			game->a_top = game->a_stack;
		}
		else
		{
			if (!(game->a_stack->prev = ft_memalloc(sizeof(t_stack))))
				return (-1);
			game->a_stack->prev->next = game->a_stack;
			game->a_stack = game->a_stack->prev;			
		}
		if (!ft_check_duplicates(game, argv[i++]))
			return (-1);
	}
	game->a_size = argc - 1;
	return (1);
}
