/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:51:02 by msharifi          #+#    #+#             */
/*   Updated: 2022/05/30 14:46:32 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack **stack)
{
	size_t	i;
	int		tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = stack->array[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = tmp;
	}
}

void	reverse_stack(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->size - 1] = tmp
	}
}

void	push_stack(t_stack *stack_1, t_stack *stack_2)
{
	if (stack_2->size > 1)
	{
		stack_1->size++;
		reverse_rotate_stack(stack_1);
		stack_1[0] = stack_2[0];
		reverse_stack(stack_2);
		stack_2->size--;
	}
}

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[0];
		stack->array[0] = stack_2->array[1];
		stack->array[1] = tmp;
	}
}