/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:00:05 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/06 17:14:24 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(t_list *stack)
{
	t_list	*save;

	if (!stack || !stack->next)
		return (0);
	while (stack)
	{
		save = stack->next;
		while (save)
		{
			if (stack->content == save->content)
				return(0);
			save = save->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	is_arg_valid(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-')
				j++;
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

t_list	*init_list(int ac, char **av)
{
	t_list	*stack;
	int		i;

	stack = ft_lstnew(ft_atoi(av[1]));
	i = 2;
	while (i < ac)
	{
		insert_last(&stack, ft_atoi(av[i]));
		i++;
	}
	return (stack);
}
