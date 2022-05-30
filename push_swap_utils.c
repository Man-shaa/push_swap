/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:29:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/05/30 14:49:14 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	void	*tmp;
	size_t	i;

	tmp = NULL;
	i = 0;
	while (i < stack->size)
	{
		if (tmp > stack->array[i])
			return (0);
		tmp = stack->array[i];
		i++;
	}
	return (1);
}

ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
