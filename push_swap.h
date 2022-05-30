/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:00:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/05/30 14:45:52 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
    int		*content;
	t_stack	*next;
}				t_stack;

typedef struct	s_struct
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_struct;

void	reverse_rotate_stack(t_stack *stack);
void	reverse_stack(t_stack *stack);
void	push_stack(t_stack *stack_1, t_stack *stack_2);
void	swap_stack(t_stack *stack);


#endif