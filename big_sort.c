/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:01:37 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 01:30:08 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*select_cheapest(t_stack *stack)
{
	t_stack	*travel;
	int		cheapest;

	cheapest = stack->cost;
	travel = stack;
	while (travel)
	{
		if (travel->cost < cheapest)
			cheapest = travel->cost;
		travel = travel->next;
	}
	while (stack)
	{
		if (stack->cost == cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
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

int	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	while (ft_lstsize(*stack_b) > 0)
	{
		set_cost(*stack_a, *stack_b);
		cheap = select_cheapest(*stack_b);
		// printf("	Cheapest : %d with %d cost\n\n", cheap->number, cheap->cost);
		get_cheap_top_b(stack_b, cheap);
		setup_a(stack_a, cheap->pos_in_a);
		push(stack_b, stack_a, 'a');
		// print_stack(*stack_a, "AFTER OP STACK A");
		// print_stack(*stack_b, "AFTER OP STACK B");
		reset_data(*stack_b);
	}
	// print_stack(*stack_a, "BEFORE A");
	rearrange_stack_a(stack_a);
	return (0);
}

void	get_cheap_top_b(t_stack **stack_b, t_stack *cheap)
{
	t_stack	*travel;
	int		pos_in_b;

	travel = *stack_b;
	pos_in_b = 0;
	while (travel && travel != cheap)
	{
		pos_in_b++;
		travel = travel->next;
	}
	if (pos_in_b < ft_lstsize(*stack_b) / 2 + 1)
	{
		while (pos_in_b > 0)
		{
			rotate(stack_b, 'b');
			pos_in_b--;
		}
		return ;
	}
	pos_in_b = ft_lstsize(*stack_b) - pos_in_b;
	while (pos_in_b > 0)
	{
		rev_rotate(stack_b, 'b');
		pos_in_b--;	
	}
}

void	setup_a(t_stack **stack_a, int pos)
{
	if (pos < ft_lstsize(*stack_a) / 2 + 1)
	{
		while (pos > 0)
		{
			rotate(stack_a, 'a');
			pos--;
		}
		return ;
	}
	pos = ft_lstsize(*stack_a) - pos;
	while (pos > 0)
	{
		rev_rotate(stack_a, 'a');
		pos--;	
	}
}
