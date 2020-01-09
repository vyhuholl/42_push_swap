/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:51:58 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/09 18:44:49 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** A function to swap the first two elements
** at the top of stack A, stack B or both.
*/

void	ft_op_swap(t_game *game, int op)
{

}

/*
** A function to push the first element at the top of one stack to another.
*/

void	ft_op_push(t_game *game, int op)
{

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

/*
** A function to execute an operation.
*/

void	ft_do_op(t_game *game, int op)
{
	if (op < 4)
		ft_op_swap(game, op);
	else if (op > 3 && op < 6)
		ft_op_push(game, op);
	else if (op > 5 && op < 9)
		ft_op_rotate(game, op);
	else if (op > 8)
		ft_op_reverse_rotate(game, op);
}
