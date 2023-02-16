/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:49:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/16 17:36:37 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (exec_op(stack_a, stack_b, line))
		{
			free_all(stack_a, stack_b);
			ft_free(line);
			write(STDERR_FILENO, "Error\n", 6);
			return (1);
		}
		ft_free(line);
		line = get_next_line(0);
	}
	if (!is_sorted(*stack_a))
	{
		write(STDOUT_FILENO, "KO\n", 3);
		free_all(stack_a, stack_b);
		return (5);
	}
	write(STDOUT_FILENO, "OK\n", 3);
	return (0);
}

// Compare 2 char *
// Return 1 si elles sont les memes, sinon 0
int	is_same(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

int	exec_op(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (is_same(line, "pa\n"))
		return (push(stack_b, stack_a, 'x'), 0);
	else if (is_same(line, "pb\n"))
		return (push(stack_a, stack_b, 'x'), 0);
	else if (is_same(line, "sa\n"))
		return (swap(stack_a, 'x'), 0);
	else if (is_same(line, "sb\n"))
		return (swap(stack_b, 'x'), 0);
	else if (is_same(line, "ss\n"))
		return (ss(stack_a, stack_b, 'x'), 0);
	else if (is_same(line, "ra\n"))
		return (rotate(stack_a, 'x'), 0);
	else if (is_same(line, "rb\n"))
		return (rotate(stack_b, 'x'), 0);
	else if (is_same(line, "rr\n"))
		return (rr(stack_a, stack_b, 'x'), 0);
	else if (is_same(line, "rra\n"))
		return (rev_rotate(stack_a, 'x'), 0);
	else if (is_same(line, "rrb\n"))
		return (rev_rotate(stack_b, 'x'), 0);
	else if (is_same(line, "rrr\n"))
		return (rrr(stack_a, stack_b, 'x'), 0);
	return (1);
}
