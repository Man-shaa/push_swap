/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:16:29 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/14 18:35:57 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void *addr)
{
	if (addr)
		free(addr);
	addr = NULL;
}

void	free_list(t_stack **stack)
{
	t_stack *before;
	t_stack	*tmp;

	before = *stack;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		ft_free(before);
		before = tmp;
	}
	ft_free(stack);
}

void	free_all(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
}
