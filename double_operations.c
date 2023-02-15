/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:45:03 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 16:03:53 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	write(STDOUT_FILENO, "rr\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a, 'r');
	rev_rotate(stack_b, 'r');
	write(STDOUT_FILENO, "rrr\n", 4);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 'r');
	swap(stack_b, 'r');
	write(STDOUT_FILENO, "ss\n", 3);
}
