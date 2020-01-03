/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:18:49 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/03 18:00:09 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to perform operations with stacks.
*/

/*
** A function to read a stack from user input.
** Returns the size of a stack. In case of an error,
** the return value is negative.
*/

int	ft_read_stack(int argc, char **argv, t_stack *stack)
{
	t_dlist	*node;
	int		i;

	i = 0;
	if (!ft_check_duplicates(argc, argv))
		return (-1);
	node->next = NULL;
	while (i < argc)
	{
		i++;
	}
	stack->head = node;
	stack->tail = node->prev;
	stack->size = argc;
	return (stack->size);
}
