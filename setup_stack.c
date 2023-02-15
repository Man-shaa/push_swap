/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:12:11 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 01:43:06 by msharifi         ###   ########.fr       */
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

void	rearrange_stack_a(t_stack **stack_a)
{
	t_stack	*travel;
	int		i;

	i = 1;
	travel = *stack_a;
	if (is_sorted(*stack_a))
		return ;
	while (travel->next && travel->index < travel->next->index)
	{
		travel = travel->next;
		i++;
	}
	setup_a(stack_a, i);
}

void	reset_data(t_stack *stack)
{
	while (stack)
	{
		stack->cost = 0;
		stack->pos_in_a = 0;
		stack = stack->next;
	}
}
