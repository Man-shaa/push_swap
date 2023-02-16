/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:00:50 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 16:30:04 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	if (parsing(ac, av))
		return (1);
	stack_a = create_stack(ac, av, stack_a);
	if (!stack_a)
		return (err_msg("Malloc failed", NULL, 2));
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
		return (free_all(stack_a, stack_b), err_msg("Malloc failed", NULL, 3));
	*stack_b = NULL;
	if (checker(stack_a, stack_b))
		return (4);
	free_all(stack_a, stack_b);
	return (0);
}
