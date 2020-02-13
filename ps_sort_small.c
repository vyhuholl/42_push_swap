/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:36:34 by sghezn            #+#    #+#             */
/*   Updated: 2020/02/13 23:55:40 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Utility functions to sort small stacks.
*/

/*
** A function to determine how the first three numbers are arranged in a stack.
** Return cases:
** 1 – 1 2 3
** 2 – 1 3 2
** 3 – 2 1 3
** 4 – 2 3 1
** 5 – 3 1 2
** 6 – 3 2 1
*/

int		ft_ps_three_numbers_case(t_stack *stack)
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
	return (0);
}

/*
** A function to sort stack A with size > 3.
*/

void	ft_ps_sort_more_than_three_a(t_game *game, int size, int var)
{
	if (var == 4)
	{
		ft_ps_do_op(game, RA);
		ft_ps_do_op(game, SA);
		ft_ps_do_op(game, RRA);
		ft_ps_do_op(game, SA);
	}
	else if (var == 5)
	{
		ft_ps_do_op(game, SA);
		ft_ps_do_op(game, RA);
		ft_ps_do_op(game, SA);
		ft_ps_do_op(game, RRA);
	}
	else if (var == 6)
	{
		ft_ps_do_op(game, SA);
		ft_ps_do_op(game, RA);
		ft_ps_do_op(game, SA);
		ft_ps_do_op(game, RRA);
		ft_ps_do_op(game, SA);
	}
}

/*
** A function to sort a small stack A.
*/

void	ft_ps_sort_small_a(t_game *game, int size)
{
	int	var;

	var = game->a_size < 3 ? 0 : ft_ps_three_numbers_case(game->a_top);
	if (game->a_size > 3)
		ft_ps_sort_more_than_three_a(game, size, var);
	else if (size == 2 && game->a_top->value > game->a_top->prev->value)
		ft_ps_do_op(game, SA);
	else if (var == 2)
	{
		ft_ps_do_op(game, RA);
		ft_ps_do_op(game, SA);
		ft_ps_do_op(game, RRA);
	}
	else if (var == 3)
		ft_ps_do_op(game, SA);
	else if (var == 4)
		ft_ps_do_op(game, RRA);
	else if (var == 5)
		ft_ps_do_op(game, RA);
	else if (var == 6)
	{
		ft_ps_do_op(game, SA);
		ft_ps_do_op(game, RRA);
	}
}

/*
** A function to sort stack B with size > 3.
*/

void	ft_ps_sort_more_than_three_b(t_game *game, int size, int var)
{
	
}

/*
** A function to sort a small stack B.
*/

void	ft_ps_sort_small_b(t_game *game, int size)
{
	int	var;
	int flag;

	var = game->b_size < 3 ? 0 : ft_ps_three_numbers_case(game->b_top);
	flag = game->b_size > 3 ? 0 : 1;
	if (game->b_size > 3)
		ft_ps_sort_more_than_three_b(game, size, var);
	else if (size == 2 && game->b_top->value < game->b_top->prev->value)
		ft_ps_do_op(game, SB);
	else if (var == 1)
	{
		ft_ps_do_op(game, SB);
		ft_ps_do_op(game, RRB);		
	}
	while (flag && var != 5 && game->b_size)
		ft_ps_do_op(game, PA);
}
