/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:12:08 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/11 18:11:55 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int ac, char **av)
{
	t_list	*stack;

	if (!is_arg_valid(av))
		return (write(1, "Error\n", 6), 0);
	if (ac <= 2)
		return (0);
	stack = init_list(ac, av);
	if (!parsing(stack))
		return (free_list(&stack), write(1, "Error\n", 6), 0);
	if (!is_sort(stack))
		return (free_list(&stack), 0);
	return (free_list(&stack), 1);
}

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

	if (!parse(ac, av))
		return (0);
	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = init_list(ac, av);	
	*stack_b = NULL;
	print_list(stack_a);
	if (ft_lstsize(*stack_a) <= 5)
		sort_small(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	print_list(stack_a);
	print_index(stack_a);
	free_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
