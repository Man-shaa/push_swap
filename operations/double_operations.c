/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:45:03 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 23:27:40 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b, char c)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	if (c == 'd')
		write(STDOUT_FILENO, "rr\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, char c)
{
	rev_rotate(stack_a, 'r');
	rev_rotate(stack_b, 'r');
	if (c == 'd')
		write(STDOUT_FILENO, "rrr\n", 4);
}

void	ss(t_stack **stack_a, t_stack **stack_b, char c)
{
	swap(stack_a, 'r');
	swap(stack_b, 'r');
	if (c == 'd')
		write(STDOUT_FILENO, "ss\n", 3);
}
