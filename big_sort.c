/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:01:37 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/14 23:06:50 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*select_cheapest(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*travel;
	int		cheapest;

	cheapest = stack->cost;
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

int	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	// (void)stack_a;
	// (void)stack_b;
	t_stack	*cheap;

	while (ft_lstsize(*stack_b) > 0)
	{
		set_cost(*stack_a, *stack_b);
		cheap = select_cheapest(*stack_a);
		get_cheap_top_b(stack_b, cheap);
	}
	return (0);
}

void	get_cheap_top_b(t_stack *stack_b, t_stack *cheap)
{
	
}
