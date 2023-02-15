/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:57:13 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 01:51:11 by msharifi         ###   ########.fr       */
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
		// printf("Number : %d wants to be at pos [%d]	|	Cost : %d\n", tmp->number, tmp->pos_in_a, tmp->cost);
		tmp = tmp->next;
	}
}

void	total_cost(t_stack *stack_a, t_stack *stack_b, t_stack *tmp)
{
	cost_to_top_b(stack_b, tmp);
	cost_setup_a(stack_a, tmp);
	tmp->cost += 1;
}

int	cost_to_top_b(t_stack *stack, t_stack *tmp)
{
	int		pos_in_b;
	int		cost_ret;
	t_stack	*travel;

	pos_in_b = 0;
	cost_ret = 0;
	travel = stack;
	while (travel && travel->index != tmp->index)
	{
		pos_in_b++;
		cost_ret++;
		travel = travel->next;
	}
	if (pos_in_b < ft_lstsize(stack) / 2 + 1)
	{
		cost_ret = pos_in_b;
		tmp->cost = pos_in_b;
	}
	else
	{
		tmp->cost = ft_lstsize(stack) - pos_in_b;
		cost_ret = ft_lstsize(stack) - pos_in_b;
	}
	return (cost_ret);
}

int	cost_setup_a(t_stack *stack, t_stack *tmp)
{
	int	cost_ret;

	cost_ret = 0;
	if (tmp->pos_in_a < ft_lstsize(stack) / 2 + 1)
	{
		cost_ret = tmp->pos_in_a;
		tmp->cost += tmp->pos_in_a;
	}
	else if (tmp->pos_in_a == ft_lstsize(stack) / 2 + 1)
	{
		cost_ret = tmp->pos_in_a - 1;
		tmp->cost += tmp->pos_in_a - 1;
	}
	else
	{
		tmp->cost += ft_lstsize(stack) - tmp->pos_in_a;
		cost_ret = ft_lstsize(stack) - tmp->pos_in_a;
	}
	return (cost_ret);
}
