/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:23:32 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/11 18:29:50 by msharifi         ###   ########.fr       */
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

int	get_max_bits_index(t_list *lst)
{
	int	n;
	int	save_val;

	save_val = 0;
	while (lst)
	{
		if (save_val < lst->index)
			save_val = lst->index;
		lst = lst->next;
	}
	while (save_val != 0)
	{
		save_val /= 10;
		n++;
	}
	return (n);
}
