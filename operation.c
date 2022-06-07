/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:51:02 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/07 17:44:38 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list *stack)
{
	int		tmp_content;
	int		tmp_index;
	t_list	*tmp_next;

	if (ft_lstsize(stack) <= 1)
		return ;
	tmp_content = stack->content;
	tmp_index = stack->index;
	tmp_next = stack->next;
	stack->content = tmp_next->content;
	stack->index = tmp_next->index;
	stack = stack->next;
	stack->content = tmp_content;
	stack->index = tmp_index;
}

void	rotate_stack(t_list **stack)
{
	int		tmp;
	t_list	*prev;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack)->content;
	prev = (*stack);
	(*stack) = (*stack)->next;
	free(prev);
	insert_last(stack, tmp);
}

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*last_node;
	t_list	*before_last_node;

	if (ft_lstsize(*stack) <= 1)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	before_last_node = find_prev_elem(*stack, last_node->content);
	before_last_node->next = NULL;
	*stack = last_node;
}

void	push_stack(t_list **stack1, t_list **stack2)
{
	t_list	*new;

	if (!ft_lstsize(*stack2))
		return ;
	new = ft_lstnew((*stack2)->content);
	new->next = *stack1;
	*stack1 = new;
	delete_node(stack2, (*stack2)->content);
}
