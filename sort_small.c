/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:12:43 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/13 18:37:45 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stack, char c)
{
	t_list	*after;
	t_list	*head;

	head = *stack;
	after = head->next;
	if (head->index > after->index)
		swap_stack(*stack, c);
}

void	sort_3(t_list **stack, char c)
{
	t_list	*after;
	t_list	*head;

	sort_2(stack, 'a');
	while (is_sort(*stack))
	{
		head = *stack;
		after = head->next;
		if (head->index > after->index)
			swap_stack(*stack, c);
		else
			reverse_rotate_stack(stack, c);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b, int x)
{
	if (find_index(*stack_a, x) < 2)
	{
		while ((*stack_a)->index != x)
			rotate_stack(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != x)
			reverse_rotate_stack(stack_a, 'a');
	}
	push_stack(stack_b, stack_a, 'b');
	sort_3(stack_a, 'a');
	push_stack(stack_a, stack_b, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (find_index(*stack_a, 0) < 3)
	{
		while ((*stack_a)->index != 0)
			rotate_stack(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != 0)
			reverse_rotate_stack(stack_a, 'a');
	}
	push_stack(stack_b, stack_a, 'b');
	sort_4(stack_a, stack_b, 1);
	push_stack(stack_a, stack_b, 'a');
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort_2(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a, 'a');
	else if (ft_lstsize(*stack_a) == 4)
		sort_4(stack_a, stack_b, 0);
	else if (ft_lstsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
}
