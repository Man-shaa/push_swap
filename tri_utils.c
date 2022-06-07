/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:23:32 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/07 17:53:00 by msharifi         ###   ########.fr       */
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

int	get_max_bits(t_list *lst)
{
	int	n;
	int	save_val;
	int	content;

	save_val = 0;
	n = 0;
	indexing(lst);
	while (lst)
	{
		if (lst->index > save_val)
		{
			save_val = lst->index;
			content = lst->content;
		}
		lst = lst->next;
	}
	while (content != 0)
	{

		content /= 10;
		n++;
	}
	return (n);
}
