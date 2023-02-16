/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:09:49 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 16:28:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char *name)
{
	if (!stack)
		return ;
	printf("\n%s\n\n", name);
	while (stack)
	{
		printf("Number : %d	|	Index : %d	|	Cost : %d\n", stack->number, stack->index, stack->cost);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack		**stack_a;
	t_stack		**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 2)
		return (err_msg("tuto : arg > 2", NULL, 1));
	if (parsing(ac, av))
		return (1);
	stack_a = create_stack(ac, av, stack_a);
	if (!stack_a)
		return (err_msg("Malloc failed", NULL, 2));
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
		return (free_all(stack_a, stack_b), err_msg("Malloc failed", NULL, 3));
	if (set_up_stack(stack_a, stack_b))
		return (0);
	if (ac > 6)
		big_sort(stack_a, stack_b);
	else
		small_sort(stack_a, stack_b);
	// print_stack(*stack_a, "FINAL A");
	// printf("%d\n\n\n", is_sorted(*stack_a));
	free_all(stack_a, stack_b);
	return (0);
}
