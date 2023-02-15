/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:38:53 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 01:50:33 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_1, t_stack **stack_2, char c)
{
	t_stack	*save_1;

	save_1 = *stack_1;
	if (!save_1)
		return ;
	*stack_1 = save_1->next;
	save_1->next = *stack_2;
	*stack_2 = save_1;
	if (c == 'a')
		write(STDOUT_FILENO, "pa\n", 3);
	else if (c == 'b')
		write(STDOUT_FILENO, "pb\n", 3);
}

// premier devient dernier ---- SHIFT UP
void	rotate(t_stack **stack, char c)
{
	t_stack	*first;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	*stack = first->next;
	ft_lstlast(*stack)->next = first;
	first->next = NULL;
	if (c == 'a')
		write(STDOUT_FILENO, "ra\n", 3);
	else if (c == 'b')
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rev_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (ft_lstsize(*stack) < 2)
		return ;
	last = ft_lstlast(*stack);
	prev_last = *stack;
	while (prev_last->next && prev_last->next != ft_lstlast(*stack))
		prev_last = prev_last->next;
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c == 'a')
		write(STDOUT_FILENO, "rra\n", 4);
	else if (c == 'b')
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	swap(t_stack **stack, char c)
{
	t_stack	*first;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = (*stack)->next;
	(*stack)->next = first;
	if (c == 'a')
		write(STDOUT_FILENO, "sa\n", 3);
	else if (c == 'b')
		write(STDOUT_FILENO, "sb\n", 3);
}
