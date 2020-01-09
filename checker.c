/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:57:44 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/09 17:50:20 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** A function to read an operation from user input.
** Returns operation number or -1 in case of an invalid input.
*/

int	ft_checker_read_op(char *line)
{
	int	op;
	int	i;

	if (line[0] != 's' && line[0] != 'p' && line[0] != 'r')
		return (-1);
	op = 0;
	if (line[0] != 's')
		op += ((line[0] == 'p') ? 3 : 5);
	i = 0;
	while (line[++i])
	{
		if (!(line[i] == 'a' || line[i] == 'b' ||
			(line[i] == line[i - 1] && line[i - 1] != 'p')))
			return (-1);
		if (line[i] == 'a' || line[i] == line[i - 1])
			op += 1;
		if (line[i] == 'b' || line[i] == line[i - 1])
			op += 2;
	}
	return (op);
}

/*
** A function to execute an operation.
** (Returns -1 in case of an invalid input)
*/

int	ft_checker_do_op(t_game *game, char *line)
{
	size_t	len;
	int		op;

	len = ft_strlen(line);
	if (len < 3 || len > 4 || line[len - 1] != '\n')
	{
		ft_memdel((void**)&line);
		return (-1);
	}
	line[len - 1] = '\0';
	if ((op = ft_checker_read_op(line)))
		ft_do_op(game, op));
	ft_memdel((void**)&line);
	return (1);
}

/*
** The main checker function.
*/

int	main(int argc, char **argv)
{
	t_game	game;
	char	*line;
	int		ret;

	if (argc < 2)
		return (0);
	ft_bzero(&game, sizeof(game));
	if (!ft_read_stack(&game, argc, argv) || !ft_index(&game, argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	while ((ret = get_next_line(0, &line)) != 0)
	{
		if (ft_checker_do_op(game, line) == -1 || ret == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	}
	ft_is_sorted(game->a_top) ? ft_putstr("OK\n") : ft_putstr("KO\n");
	return (0);
}
