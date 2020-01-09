/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:57:44 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/07 20:56:43 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The main checker function.
*/

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		return (0);
	ft_bzero(&game, sizeof(game));
	if (!ft_read_stack(&game, argc, argv) || !ft_index_stack(&game))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}
