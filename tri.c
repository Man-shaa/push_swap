/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:23:32 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/06 17:14:27 by msharifi         ###   ########.fr       */
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
