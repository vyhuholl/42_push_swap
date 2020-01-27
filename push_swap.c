/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:08:47 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/27 21:03:45 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** A function to print a single instruction.
*/

void	ft_ps_print_op(int op)
{
	if (op == 1)
		ft_putstr("sa\n");
	else if (op == 2)
		ft_putstr("sb\n");
	else if (op == 3)
		ft_putstr("ss\n");
	else if (op == 4)
		ft_putstr("pa\n");
	else if (op == 5)
		ft_putstr("pb\n");
	else if (op == 6)
		ft_putstr("ra\n");
	else if (op == 7)
		ft_putstr("rb\n");
	else if (op == 8)
		ft_putstr("rr\n");
	else if (op == 9)
		ft_putstr("rra\n");
	else if (op == 10)
		ft_putstr("rrb\n");
	else if (op == 11)
		ft_putstr("rrr\n");
}

/*
** A function to print a list of instructions.
*/

void	ft_ps_print_res(t_stack *res)
{
	t_stack	*ptr;

	ptr = res;
	while (ptr)
	{
		ft_ps_print_op(ptr->value);
		ptr = ptr->next;
	}
}

/*
** The main push_swap function.
*/

int		main(int argc, char **argv)
{
	t_game	game;
	t_stack	*res;

	if (argc < 2)
		return (0);
	ft_bzero(&game, sizeof(game));
	if (!ft_read_stack(&game, argc, argv) || !ft_index(&game, argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ft_is_sorted(&game->a_top))
		return (0);
	ft_ps_print_res(res);
	ft_del_stack(&res);
	return (0);
}
