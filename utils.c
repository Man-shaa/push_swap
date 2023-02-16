/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:05:05 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 22:06:28 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	err_msg(char *str, char *end, int ret)
{
	if (str || end)
		write(STDERR_FILENO, "Error\n", 6);
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	if (end)
		write(STDERR_FILENO, end, ft_strlen(end));
	if (str || end)
		write(STDERR_FILENO, "\n", 1);
	return (ret);
}

long long	ft_atoi(char *str)
{
	int			sign;
	long long	res;
	int			i;

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
		if ((res > 2147483647 && sign == 1) || (res < -2147483648 && sign == -1))
		{
			err_msg(str, " is not in the range of an integer", 1);
			exit (1);
		}
		i++;
	}
	return (res * sign);
}
