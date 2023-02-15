/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:09:49 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 01:49:28 by msharifi         ###   ########.fr       */
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
		return (1);
	if (ac <= 6)
		return (err_msg("args > 5 for now", NULL, 2));
	if (parsing(ac, av))
		return (3);
	stack_a = create_stack(ac, av, stack_a);
	if (!stack_a)
		return (err_msg("Malloc failed", NULL, 4));
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
		return (err_msg("Malloc failed", NULL, 5));
	if (set_up_stack(stack_a, stack_b))
		return (0);
	big_sort(stack_a, stack_b);
	free_all(stack_a, stack_b);
	return (0);
}
