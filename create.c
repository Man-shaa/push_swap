/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:18:20 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 18:40:42 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**create_stack(int ac, char **av, t_stack **stack)
{
	int	i;

	i = 1;
	stack = malloc(sizeof(t_stack *));
	*stack = NULL;
	if (!stack)
		return (NULL);
	while (i < ac)
	{
		if (add_last(stack, ft_atoi(av[i])))
			return (NULL);
		i++;
	}
	return (stack);
}
