/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:57:13 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/14 23:05:41 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_b;
	while (tmp)
	{
		find_pos_in_a(stack_a, tmp);
		total_cost(stack_a, stack_b, tmp);
		printf("Number : %d wants to be at pos [%d]	|	Cost : %d\n", tmp->number, tmp->pos_in_a, tmp->cost);
		tmp = tmp->next;
	}
	print_stack(stack_b, "COST STACK B");
}

void	total_cost(t_stack *stack_a, t_stack *stack_b, t_stack *tmp)
{
	int	save;
	cost_to_top_b(stack_b, tmp);
	printf("(%d)	Cost to get on top of B : %d\n", tmp->number, tmp->cost);
	save = tmp->cost;
	cost_setup_a(stack_a, tmp);
	printf("(%d)	Cost to setup A : %d\n", tmp->number, tmp->cost - save);
	tmp->cost += 1;
}

void	cost_to_top_b(t_stack *stack, t_stack *tmp)
{
	int		pos_in_b;
	t_stack	*travel;

	pos_in_b = 0;
	travel = stack;
	while (travel && travel->index != tmp->index)
	{
		pos_in_b++;
		travel = travel->next;
	}
	if (pos_in_b < ft_lstsize(stack) / 2 + 1)
		tmp->cost = pos_in_b;
	else
		tmp->cost = ft_lstsize(stack) - pos_in_b;
}

void	cost_setup_a(t_stack *stack, t_stack *tmp)
{
	if (tmp->pos_in_a < ft_lstsize(stack) / 2 + 1)
		tmp->cost += tmp->pos_in_a;
	else if (tmp->pos_in_a == ft_lstsize(stack) / 2 + 1)
		tmp->cost += tmp->pos_in_a - 1;
	else
		tmp->cost += ft_lstsize(stack) - tmp->pos_in_a;
}
