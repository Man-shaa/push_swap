/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:06:29 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/08 17:41:28 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_list *stack_a, t_list *stack_b)
{
	if (swap_stack(stack_a, 's') == -1 || swap_stack(stack_b, 's') == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate_stack(stack_a, 's') == -1
		|| reverse_rotate_stack(stack_b, 's') == -1)
		return (-1);
	ft_putendl_fd("rrr", 1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((rotate_stack(stack_a, 's') == -1) || (rotate_stack(stack_b, 's') == -1))
		return (-1);
	ft_putendl_fd("rr", 1);
	return (0);
}
