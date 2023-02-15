/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:01:37 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 20:38:46 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	while (ft_lstsize(*stack_b) > 0)
	{
		set_cost(*stack_a, *stack_b);
		cheap = select_cheapest(*stack_b);
		// printf("	Cheapest : %d with %d cost\n\n", cheap->number, cheap->cost);
		get_cheap_top_b(stack_a, stack_b, cheap);
		if (cheap->cost_a != 0)
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

void	do_both_op(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	if (cheap->pos_in_b < ft_lstsize(*stack_b) / 2 + 1
		&& cheap->pos_in_a < ft_lstsize(*stack_a) / 2 + 1)
	{
		while (cheap->pos_in_b > 0 && cheap->pos_in_a > 0)
		{
			cheap->pos_in_b--;
			cheap->pos_in_a--;
			rr(stack_a, stack_b);
		}
	}
	else if (cheap->pos_in_b > ft_lstsize(*stack_b) / 2 + 1
		&& cheap->pos_in_a > ft_lstsize(*stack_a) / 2 + 1)
	{
		while (cheap->pos_in_b < ft_lstsize(*stack_b)
			&& cheap->pos_in_a < ft_lstsize(*stack_a))
		{
			cheap->pos_in_b++;
			cheap->pos_in_a++;
			rrr(stack_a, stack_b);
		}
		if (cheap->pos_in_b == ft_lstsize(*stack_b))
			cheap->pos_in_b = 0;
		if (cheap->pos_in_a == ft_lstsize(*stack_a))
			cheap->pos_in_a = 0;
	}
}

void	get_cheap_top_b(t_stack **stack_a, t_stack **stack_b, t_stack *c)
{
	t_stack	*travel;

	travel = *stack_b;
	do_both_op(stack_a, stack_b, c);
	if (c->cost_b == 0)
		return ;
	if (c->pos_in_b < ft_lstsize(*stack_b) / 2 + 1)
	{
		while (c->pos_in_b > 0)
		{
			rotate(stack_b, 'b');
			c->pos_in_b--;
		}
		return ;
	}
	c->pos_in_b = ft_lstsize(*stack_b) - c->pos_in_b;
	while (c->pos_in_b > 0)
	{
		rev_rotate(stack_b, 'b');
		c->pos_in_b--;
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
