/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:36:34 by sghezn            #+#    #+#             */
/*   Updated: 2020/02/07 18:01:18 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Utility functions to sort stacks with size 3 or less.
*/

/*
** A function to determine how three numbers are arranged in a stack.
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
	if (!stack || !(stack->prev) || !(stack->prev->prev))
		return (0);
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
** A function to sort stack A with size 3.
*/

void	ft_ps_sort_three_a(t_game *game, int size, int case)
{
	if (case == 2 && game->a_size == 3)
	{
		ft_ps_do_op(game, RA);
		ft_ps_do_op(game, SA);
		ft_ps_do_op(game, RRA);
	}
	else if (case == 3 && game->a_size == 3)
		ft_ps_do_op(game, SA);
	else if (case == 4)
	{
		if (game->a_size == 3)
			ft_ps_do_op(game, RRA);
		else
		{
			ft_ps_do_op(game, RA);
			ft_ps_do_op(game, SA);
			ft_ps_do_op(game, RRA);
			ft_ps_do_op(game, SA);
		}
	}
}

/*
** A function to sort stack B with size 3.
*/

void	ft_ps_sort_three_b(t_game *game, int size, int case)
{
	if (case == 2 && game->b_size == 3)
	{
		ft_ps_do_op(game, PA);
		ft_ps_do_op(game, SB);
	}
	else if (case == 3 && game->b_size == 3)
		ft_ps_do_op(game, SB);
}

/*
** A function to sort stack A with size 3 or less.
*/

void	ft_ps_sort_small_a(t_game *game, int size)
{
	int	case;

	case = ft_ps_three_numbers_case(game->a_top);
	if (size == 2 && game->a_top->value > game->a_top->prev->value)
		ft_ps_do_op(game, SA);
	else if (size == 3)
		ft_ps_sort_three_a(game, size, case);
}

/*
** A function to sort stack B with size 3 or less.
*/

void	ft_ps_sort_small_b(t_game *game, int size)
{
	int	case;

	case = ft_ps_three_numbers_case(game->b_top);
	if (size == 2)
	{
		if (game->b_top->value > game->b_top->prev->value)
			ft_do_op(game, SB);
		ft_do_op(game, SA);
		ft_do_op(game, SA);
	}
	else if (size == 3)
	{
		ft_ps_sort_three_b(game, size, case);
		while (game->b_size <= 3 && game->b_size > 0)
			ft_ps_do_op(game, PA);
	}
}
