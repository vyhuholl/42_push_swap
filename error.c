/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:36:23 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/07 21:56:40 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Utility functions for error management.
*/

/*
** A function to check whether a string is valid.
** (i. e. can be converted to integer)
*/

int	ft_is_numeric(char *str)
{
	int i;

	if (!str || ((str[0] == '-' || str[0] == '+') && !str[1]))
		return (-1);
	i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (-1);
	}
	return (1);
}

/*
** A function to convert an ASCII string to integer.
** (returns -1 if a number is too large or too small)
*/

int	ft_atoi_limit(t_game *game, char *nbr, int *res)
{
	int		sign;
	long	max;
	long	n;

	while ((*nbr >= 9 && *nbr <= 13) || *nbr == ' ')
		nbr++;
	sign = (*nbr == '-') ? -1 : 0;
	max = INT_MAX - sign;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	n = 0;
	while (ft_isdigit(*nbr))
	{
		n = n * 10 + *(nbr++) - 48;
		if (n > max)
			return (-1);
	}
	if (*nbr)
		return (-1);
	*res = (sign == -1) ? n * sign : n;
	return (1);
}

/*
** A function which adds an element to a stack
** and returns -1 in case of an error.
** (too large/too small value or a duplicate)
*/

int	ft_check_duplicates(t_game *game, char *nbr)
{
	(game->a_size)++;
	if (!ft_atoi_limit(game, nbr, &(game->a_stack->value)))
		return (-1);
	game->b_stack = game->a_top;
	
	return (1);
}
