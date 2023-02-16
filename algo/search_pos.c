/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:39:52 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 22:10:49 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	find_pos_in_b(t_stack *stack, t_stack *tmp)
{
	tmp->pos_in_b = 0;
	while (stack && stack->index != tmp->index)
	{
		tmp->pos_in_b++;
		stack = stack->next;
	}
}

int	find_index(t_stack *stack, int x)
{
	int		i;
	t_stack	*travel;

	i = 0;
	travel = stack;
	while (travel && travel->index != x)
	{
		i++;
		travel = travel->next;
	}
	return (i);
}
