/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:23:32 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/13 19:04:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list *list)
{
	t_list	*travel;
	t_list	*head;

	head = list;
	while (list)
	{
		travel = head;
		list->index = 0;
		while (travel)
		{
			if (list->content > travel->content)
				list->index += 1;
			travel = travel->next;
		}
		list = list->next;
	}
}

int	find_index(t_list *stack, int x)
{
	int		i;
	t_list	*travel;

	i = 0;
	travel = stack;
	while (travel && travel->index != x)
	{
		i++;
		travel = travel->next;
	}
	return (i);
}

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
