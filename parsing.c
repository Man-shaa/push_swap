/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:50:29 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 22:08:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int ac, char **av)
{
	if (check_only_numbers_and_int(ac, av))
		return (2);
	if (check_duplicate(ac, av))
		return (err_msg("Duplicates found", NULL, 3));
	return (0);
}

int	check_only_numbers_and_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!av[i][0])
			return (err_msg("Args should not be empty", NULL, 1));
		if (av[i][0] == '-' && av[i][1])
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (err_msg("Args should be only numbers", NULL, 2));
			j++;
		}
		if (ft_atoi(av[i]) < -2147483648 || ft_atoi(av[i]) > 2147483647)
			return (err_msg(av[i], " is not in the range of an integer", 3));
		i++;
	}
	return (0);
}

int	check_duplicate(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack && stack->next && stack->number < stack->next->number)
		stack = stack->next;
	if (!stack->next)
		return (1);
	return (0);
}
