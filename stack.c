/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:18:49 by sghezn            #+#    #+#             */
/*   Updated: 2020/03/10 12:44:45 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions for working with stacks.
*/

/*
** A function to read input to stack A.
** Returns -1 in case of an error.
*/

int		ft_read_stack(t_game *game, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_is_numeric(argv[i]) == -1)
			return (-1);
		if (!game->a_stack)
		{
			if (!(game->a_stack = ft_memalloc(sizeof(t_stack))))
				return (-1);
			game->a_top = game->a_stack;
		}
		else
		{
			if (!(game->a_stack->prev = ft_memalloc(sizeof(t_stack))))
				return (-1);
			game->a_stack->prev->next = game->a_stack;
			game->a_stack = game->a_stack->prev;
		}
		if (ft_check_duplicates(game, argv[i]) == -1)
			return (-1);
	}
	game->a_size = argc - 1;
	return (1);
}

/*
** A function to sort the index of a stack (using quicksort).
** Returns -1 in case of a memory error.
*/

int		ft_index(t_game *game, int argc)
{
	t_stack	*ptr;
	int		*temp;
	int		i;

	if (!(temp = (int*)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	i = 0;
	ptr = game->a_top;
	while (ptr)
	{
		temp[i++] = ptr->value;
		ptr = ptr->prev;
	}
	ft_quicksort(&temp, 0, argc - 2);
	ft_index_util(game, temp, argc);
	free(temp);
	return (1);
}

/*
** A function to execute an operation on stack A, stack B or both.
*/

void	ft_do_op(t_game *game, int op)
{
	if (op < 4)
		ft_op_swap(game, op);
	else if (op == 4 && game->b_top)
		ft_op_push_a(game);
	else if (op == 5 && game->a_top)
		ft_op_push_b(game);
	else if (op > 5 && op < 9)
		ft_op_rotate(game, op);
	else if (op > 8)
		ft_op_reverse_rotate(game, op);
}

/*
** A function to delete one element of a stack.
*/

void	ft_del_top(t_stack **stack)
{
	t_stack	*temp;

	if (*stack)
	{
		if ((*stack)->next)
			(*stack)->next->prev = (*stack)->prev;
		if ((*stack)->prev)
			(*stack)->prev->next = (*stack)->next;
		temp = (*stack)->next;
		ft_memdel((void**)stack);
		*stack = temp;
	}
	*stack = NULL;
}

/*
** A function to delete a stack.
*/

void	ft_del_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	while (temp->prev)
	{
		temp = (*stack)->prev;
		ft_memdel((void**)stack);
		*stack = temp;
	}
	while (temp->next)
	{
		temp = (*stack)->next;
		ft_memdel((void**)stack);
		*stack = temp;
	}
	temp ? ft_memdel((void**)&temp) : 0;
	stack = NULL;
}
