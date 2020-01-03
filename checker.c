/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:57:44 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/03 17:33:08 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The main checker function.
*/

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		ft_putstr("usage: checker stack operation ...");
	if (ft_read_stack(argc, argv, &a) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}
