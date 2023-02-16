/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:26:29 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 18:39:25 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2 && (*stack_a)->index > (*stack_a)->next->index)
		swap(stack_a, 'a');
	if (size == 3)
		sort_3(stack_a);
	if (size == 4)
		sort_4(stack_a, stack_b, 0);
	if (size == 5)
		sort_5(stack_a, stack_b);
}

void	sort_3(t_stack **stack_a)
{
	if (((*stack_a)->number > (*stack_a)->next->number)
		&& ((*stack_a)->number < (*stack_a)->next->next->number))
		swap(stack_a, 'a');
	else if (((*stack_a)->number > (*stack_a)->next->next->number)
		&& ((*stack_a)->next->number > (*stack_a)->next->next->number)
		&& ((*stack_a)->number < (*stack_a)->next->number))
		rev_rotate(stack_a, 'a');
	else if (((*stack_a)->number > (*stack_a)->next->number)
		&& ((*stack_a)->next->number < (*stack_a)->next->next->number))
		rotate(stack_a, 'a');
	else if (((*stack_a)->number < (*stack_a)->next->next->number)
		&& ((*stack_a)->next->number > (*stack_a)->next->next->number))
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (((*stack_a)->number > (*stack_a)->next->number)
		&& ((*stack_a)->next->number > (*stack_a)->next->next->number))
	{
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b, int x)
{
	if (find_index(*stack_a, x) < 2)
	{
		while ((*stack_a)->index != x)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != x)
			rev_rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	if (find_index(*stack_a, 0) < 3)
	{
		while ((*stack_a)->index != 0)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != 0)
			rev_rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'b');
	sort_4(stack_a, stack_b, 1);
	push(stack_b, stack_a, 'a');
}
