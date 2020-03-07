/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:17:44 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/07 20:56:51 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Utility functions to replace or remove redundant sets of operations.
*/

void	ft_ps_op_remove(t_game *game, int op_1, int op_2, int skip)
{
	t_stack	*temp;
	t_stack	*ptr;

	ptr = game->op_list_top;
	while (ptr)
	{
		if (!ptr->next)
			break ;
		if (ptr->value == op_1)
		{
			temp = ptr->next;
			while (temp && temp->value == skip)
				temp = temp->next;
			if (temp && temp->value == op_2)
			{
				!(ptr->prev) ? game->op_list_top = ptr->next : 0;
				game->op_list_top == temp ? game->op_list_top = temp->next : 0;
				ft_del_top(&ptr);
				ft_del_top(&temp);
			}
		}
		ptr == ptr ? ptr->next : NULL;
	}
}

void	ft_ps_op_replace(t_game *game, int op_1, int op_2, int skip)
{
	t_stack	*temp;
	t_stack	*ptr;
	int		op;

	op = 1 + ((op_1 > op_2) ? op_1 : op_2);
	ptr = game->op_list_top;
	temp = NULL;
	while (ptr)
	{
		if (!ptr->next)
			break ;
		if (!temp && ptr->value == op_1)
			temp = ptr;
		if (temp && ptr->value == op_2)
		{
			temp->value = op;
			ft_del_top(&ptr);
			(temp->next && temp->next->value == op_1) ? temp = temp->next : 0;
			ptr = temp;
			temp = NULL;
			continue ;
		}
		if (ptr->value != op_1 && && ptr->value != skip && ptr->value != op)
			temp = NULL;
		ptr == ptr ? ptr->next : NULL;
	}
}
