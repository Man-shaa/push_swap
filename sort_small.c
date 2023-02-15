/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:29 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 01:50:40 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack, char c)
{
	t_stack	*after;
	t_stack	*head;

	head = *stack;
	after = head->next;
	if (head->index > after->index)
		swap(stack, c);
}

void	sort_3(t_stack **stack, char c)
{
	t_stack	*after;
	t_stack	*head;

	sort_2(stack, 'a');
	while (!is_sorted(*stack))
	{
		head = *stack;
		after = head->next;
		if (head->index > after->index)
			swap(stack, c);
		else
			rev_rotate(stack, c);
	}
}
