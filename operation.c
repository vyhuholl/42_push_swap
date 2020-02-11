/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:51:58 by sghezn            #+#    #+#             */
/*   Updated: 2020/02/11 16:42:51 by sghezn           ###   ########.fr       */
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

void	ft_op_push_a(t_game *game)
{
	t_stack	*temp;

	if (!game->b_size)
		return ;
	temp = game->b_top->prev;
	game->b_top->prev = game->a_top;
	if (!temp)
		game->b_stack = NULL;
	else
		temp->next = NULL;
	if (!game->a_top)
	{
		game->a_top = game->b_top;
		game->a_stack = game->b_top;
	}
	else
	{
		game->a_top->next = game->b_top;
		game->b_top->prev = game->a_top;
		game->a_top = game->a_top->next;
	}
	game->b_top = temp;
	(game->a_size)++;
	(game->b_size)--;
}

/*
** A function to push the first element at the top of stack A
** to stack B, using a single temporary stack.
** Increases the size of stack B and decreases the size of stack A by 1.
*/

void	ft_op_push_b(t_game *game)
{
	t_stack	*temp;

	if (!game->a_size)
		return ;
	temp = game->a_top->prev;
	game->a_top->prev = game->b_top;
	if (!temp)
		game->a_stack = NULL;
	else
		temp->next = NULL;
	if (!game->b_top)
	{
		game->b_top = game->a_top;
		game->b_stack = game->a_top;
	}
	else
	{
		game->b_top->next = game->a_top;
		game->a_top->prev = game->b_top;
		game->b_top = game->b_top->next;
	}
	game->a_top = temp;
	(game->b_size)++;
	(game->a_size)--;
}

/*
** A function to rotate all elements of stack A, stack B or both.
*/

void	ft_op_rotate(t_game *game, int op)
{
	if (op != RB && game->a_top && game->a_top != game->a_stack)
	{
		game->a_top->next = game->a_stack;
		game->a_stack->prev = game->a_top;
		game->a_top = game->a_top->prev;
		game->a_stack = game->a_stack->prev;
		game->a_top->next = NULL;
		game->a_stack->prev = NULL;
	}
	if (op != RA && game->b_top && game->b_top != game->b_stack)
	{
		game->b_top->next = game->b_stack;
		game->b_stack->prev = game->b_top;
		game->b_top = game->b_top->prev;
		game->b_stack = game->b_stack->prev;
		game->b_top->next = NULL;
		game->b_stack->prev = NULL;
	}
}

/*
** A function to reverse rotate all elements of stack A, stack B or both.
*/

void	ft_op_reverse_rotate(t_game *game, int op)
{
	if (op != RRB && game->a_stack && game->a_top != game->a_stack)
	{
		game->a_stack->prev = game->a_top;
		game->a_top->next = game->a_stack;
		game->a_top = game->a_top->next;
		game->a_stack = game->a_stack->next;
		game->a_top->next = NULL;
		game->a_stack->prev = NULL;
	}
	if (op != RRA && game->b_stack && game->b_top != game->b_stack)
	{
		game->b_stack->prev = game->b_top;
		game->b_top->next = game->b_stack;
		game->b_top = game->b_top->next;
		game->b_stack = game->b_stack->next;
		game->b_top->next = NULL;
		game->b_stack->prev = NULL;
	}
}
