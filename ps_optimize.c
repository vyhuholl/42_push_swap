/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:17:44 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/07 16:59:18 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				
			}
		}
		ptr == ptr ? ptr->next : NULL;
	}
}

void	ft_ps_op_replace(t_game *game, int op_1, int op_2, int skip)
{
	
}
