/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:51:58 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/20 19:33:09 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to execute operations on stacks.
*/

/*
** A function to swap the first two elements
** (if exist) at the top of stack A, stack B or both.
** Swaps both values and indices using a single temp integer variable.
*/

void	ft_op_swap(t_game *game, int op)
{
	int	temp;

	if (op != SB && game->a_top && game->a_top->prev)
	{
		temp = game->a_top->value;
		game->a_top->value = game->a_top->prev->value;
		game->a_top->prev->value = temp;
		temp = game->a_top->index;
		game->a_top->index = game->a_top->prev->index;
		game->a_top->prev->index = temp;
	}
	if (op != SA && game->b_top && game->b_top->prev)
	{
		temp = game->b_top->value;
		game->b_top->value = game->b_top->prev->value;
		game->b_top->prev->value = temp;
		temp = game->b_top->index;
		game->b_top->index = game->b_top->prev->index;
		game->b_top->prev->index = temp;
	}
}

/*
** A function to push the first element at the top of stack B
** to stack A, using a single temporary stack.
** Increases the size of stack A and decreases the size of stack B by 1. 
*/

void	ft_op_push_a(t_game *game, int op)
{
	t_stack	*temp;

	(game->a_size)++;
	(game->b_size)--;
}

/*
** A function to push the first element at the top of stack A
** to stack B, using a single temporary stack.
** Increases the size of stack B and decreases the size of stack A by 1. 
*/

void	ft_op_push_b(t_game *game, int op)
{
	t_stack	*temp;

	(game->b_size)++;
	(game->a_size)--;
}

/*
** A function to rotate all elements of stack A, stack B or both.
*/

void	ft_op_rotate(t_game *game, int op)
{

}

/*
** A function to reverse rotate all elements of stack A, stack B or both.
*/

void	ft_op_reverse_rotate(t_game *game, int op)
{

}
