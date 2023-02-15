/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:12:11 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 01:30:23 by msharifi         ###   ########.fr       */
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
		push(stack_a, stack_b, 'b');
	sort_3(stack_a, 'a');
	// print_stack(*stack_a, "STACK A");
	// print_stack(*stack_b, "STACK B");
	// printf("\n");
}

int	a_sorted(t_stack *stack_a, t_stack *tmp)
{
	if (is_sorted(stack_a))
	{
		if (tmp->index > ft_lstlast(stack_a)->index)
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

void	first_part_before_min(t_stack *stack, t_stack *tmp)
{
	while (stack->index < stack->next->index)
	{
		if (tmp->index < stack->index)
			return ;
		stack = stack->next;
		tmp->pos_in_a++;
	}
	if (stack->index < tmp->index && stack->index > stack->next->index)
	{
		stack = stack->next;
		tmp->pos_in_a++;
	}
}

void	find_pos_in_a(t_stack *stack, t_stack *tmp)
{
	if (a_sorted(stack, tmp))
		return ;
	if (tmp->index > ft_lstlast(stack)->index)
		return (first_part_before_min(stack, tmp));
	while (stack->index < stack->next->index)
	{
		stack = stack->next;
		tmp->pos_in_a++;
	}
	stack = stack->next;
	tmp->pos_in_a++;
	while (stack && tmp->index > stack->index)
	{
		stack = stack->next;
		tmp->pos_in_a++;
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
