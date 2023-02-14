/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:12:11 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/14 23:05:57 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_up_stack(t_stack **stack_a, t_stack **stack_b)
{
	*stack_b = NULL;
	if (is_sorted(*stack_a))
		return (free_all(stack_a, stack_b), 1);
	indexing(*stack_a);
	keep_3_in_a(stack_a, stack_b);
	return (0);
}

void	keep_3_in_a(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		push(stack_a, stack_b, 'a');
	sort_3(stack_a, 'a');
	print_stack(*stack_a, "STACK A");
	print_stack(*stack_b, "STACK B");
	printf("\n");
}

int	a_sorted(t_stack *stack_a, t_stack *tmp)
{
	t_stack	*last;

	last = stack_a;
	if (is_sorted(stack_a))
	{
		while (last->next)
			last = last->next;
		if (tmp->index > last->index)
			return (1);
		while (stack_a && tmp->index > stack_a->index)
		{
			tmp->pos_in_a++;
			stack_a = stack_a->next;
		}
		return (1);
	}
	return (0);
}

void	find_pos_in_a(t_stack *stack_a, t_stack *tmp)
{
	if (a_sorted(stack_a, tmp))
		return ;
	while (stack_a && stack_a->next && stack_a->index < stack_a->next->index)
	{
		if (tmp->index < stack_a->index)
			return ;
		tmp->pos_in_a++;
		stack_a = stack_a->next;
	}
	if (stack_a->next && tmp->index > stack_a->index && tmp->index > stack_a->next->index)
	{
		tmp->pos_in_a++;
		return ;
	}
	while (stack_a && tmp->index > stack_a->index)
	{
		tmp->pos_in_a++;
		stack_a = stack_a->next;
	}
}

void	indexing(t_stack *stack)
{
	t_stack	*travel;
	t_stack	*head;

	head = stack;
	while (stack)
	{
		travel = head;
		while (travel)
		{
			if (stack->number > travel->number)
				stack->index++;
			travel = travel->next;
		}
		stack = stack->next;
	}
}
