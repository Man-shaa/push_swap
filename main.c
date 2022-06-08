/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:12:08 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/08 17:14:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_index(t_list **lst)
{
	t_list	*ptr;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		printf("%i\n", ptr->index);
		ptr = ptr->next;
	}
	printf("\n");
}

void	print_list(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		printf("%i\n", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

void	ft_putendl_fd(char *str, int fd)
{
	while (*str)
	{
		write(1, str, fd);
		str++;
	}
	write(1, "\n", fd);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac <= 2 || !is_arg_valid(av))
		return (-1);
	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	*stack_a = init_list(ac, av);
	*stack_b = NULL;
	if (!parsing(*stack_a))
		return (free_list(stack_a), free(stack_a), free(stack_b), 0);
	print_list(stack_a);
	indexing(*stack_a);
	print_index(stack_a);
	radix_sort(stack_a, stack_b);
	print_list(stack_a);
	print_index(stack_a);
	free_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
