/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:57:13 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 17:49:48 by msharifi         ###   ########.fr       */
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
		find_pos_in_b(stack_b, tmp);
		cost_to_top_b(stack_b, tmp);
		cost_setup_a(stack_a, tmp);
		tmp->cost += 1;
		tmp->cost = tmp->cost_a + tmp->cost_b;
		// printf("Number : %d wants to be at pos [%d]	|	Cost : %d\n", tmp->number, tmp->pos_in_a, tmp->cost);
		tmp = tmp->next;
	}
}

int	cost_to_top_b(t_stack *stack, t_stack *tmp)
{
	int		pos_in_b;
	int		cost_ret;

	pos_in_b = find_index(stack, tmp->index);
	cost_ret = pos_in_b;
	if (pos_in_b < ft_lstsize(stack) / 2 + 1)
	{
		cost_ret = pos_in_b;
		tmp->cost_b = cost_ret;
	}
	else
	{
		cost_ret = ft_lstsize(stack) - pos_in_b;
		tmp->cost_b = cost_ret;
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
		tmp->cost_a = cost_ret;
	}
	else if (tmp->pos_in_a == ft_lstsize(stack) / 2 + 1)
	{
		cost_ret = tmp->pos_in_a - 1;
		tmp->cost_a = cost_ret;
	}
	else
	{
		cost_ret = ft_lstsize(stack) - tmp->pos_in_a;
		tmp->cost_a = cost_ret;
	}
	return (cost_ret);
}
