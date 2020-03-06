/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:36:34 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/06 13:14:33 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Utility functions to sort small stacks.
*/

/*
** A function to determine how the first three numbers are arranged in a stack.
** Return cases:
** 0 – the size of the stack is lesser than 3
** 1 – 1 2 3
** 2 – 1 3 2
** 3 – 2 1 3
** 4 – 2 3 1
** 5 – 3 1 2
** 6 – 3 2 1
*/

int		ft_ps_three_numbers_case(t_stack *stack)
{
	if (stack && stack->prev && stack->prev->prev)
	{
		if (stack->value < stack->prev->value
			&& stack->prev->value < stack->prev->prev->value
			&& stack->value < stack->prev->prev->value)
			return (1);
		else if (stack->value < stack->prev->value
				&& stack->value < stack->prev->prev->value)
			return (2);
		else if (stack->value > stack->prev->value
				&& stack->value < stack->prev->prev->value)
			return (3);
		else if (stack->value < stack->prev->value
				&& stack->value > stack->prev->prev->value)
			return (4);
		else if (stack->value > stack->prev->value
				&& stack->prev->value < stack->prev->prev->value)
			return (5);
		else if (stack->value > stack->prev->value
				&& stack->prev->value > stack->prev->prev->value)
			return (6);
	}
	return (0);
}

/*
** A function to sort a small stack A.
*/

void	ft_ps_sort_small_a(t_game *game, int size)
{
	int	var;

	var = ft_ps_three_numbers_case(game->a_top);
	if (size == 3 && var == 5)
		ft_ps_do_op(game, RA);
	if (size == 3 && (var == 2 || var == 4))
		ft_ps_do_op(game, RRA);
	if ((size == 3 && (var == 2 || var == 3 || var == 6)) ||
		(size == 2 && game->a_top->value > game->a_top->prev->value))
		ft_ps_do_op(game, SA);
	if (size == 3 && var == 6)
		ft_ps_do_op(game, RRA);
}

/*
** A function to sort a small stack B.
*/

void	ft_ps_sort_small_b(t_game *game, int size)
{
	int	var;

	var = ft_ps_three_numbers_case(game->b_top);
	if (size == 3 && var == 2)
		ft_ps_do_op(game, RB);
	if (size == 3 && (var == 3 || var == 5))
		ft_ps_do_op(game, RRB);
	if ((size == 3 && (var == 1 || var == 4 || var == 5)) ||
		(size == 2 && game->b_top->value < game->b_top->prev->value))
		ft_ps_do_op(game, SB);
	if (size == 3 && var == 1)
		ft_ps_do_op(game, RRB);
}
