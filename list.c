/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:01:11 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 18:02:21 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->index = 0;
	new->cost = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->pos_in_a = 0;
	new->pos_in_b = 0;
	new->next = NULL;
	return (new);
}

int	add_last(t_stack **stack, int number)
{
	t_stack	*new;

	new = ft_lstnew(number);
	if (!new)
		return (1);
	if (!*stack)
	{
		*stack = new;
		return (0);
	}
	ft_lstlast(*stack)->next = new;
	return (0);
}

int	ft_lstsize(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
