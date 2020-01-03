/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <sghezn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:35:42 by sghezn            #+#    #+#             */
/*   Updated: 2020/01/03 17:50:32 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*
** The double linked list structure.
*/

typedef struct	s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
	int						value;
}				t_dlist;

/*
** The stack structure.
*/

typedef struct	s_stack
{
	t_dlist	*head;
	t_dlist	*tail;
	int		size;
}				t_stack;

int	ft_check_duplicates(int argc, char **argv);
int	ft_read_stack(int argc, char **argv, t_stack *stack);

#endif
