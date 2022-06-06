/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:12:08 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/06 17:28:47 by msharifi         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_list	*stack;

	if (ac <= 2 || !is_arg_valid(av))
		return (0);
	stack = init_list(ac, av);
	if (!parsing(stack))
		return (free_list(&stack), 0);
	print_list(&stack);
	free_list(&stack);
	return (0);
}

// int	main()
// {
// 	t_list	*stack;
// 	t_list	*stack2;

// // initialisation stack 1
// 	stack = ft_lstnew(30);
// 	insert_last(&stack, 2147483647);
// 	insert_last(&stack, 85);
// 	insert_last(&stack, -19);

// // initialisation stack 2
// 	stack2 = ft_lstnew(7);
// 	insert_last(&stack2, 65);

// 	printf("------- STACK 1 -------\n\n");
// 	print_list(&stack);
// 	printf("------- STACK 2 -------\n\n");
// 	print_list(&stack2);

// 	printf("\n++++++++ AFTER CHANGES ++++++++\n\n\n");

// 	indexing(stack);
// 	indexing(stack2);

// 	printf("------- STACK 1 -------\n\n");
// 	print_index(&stack);
// 	printf("------- STACK 2 -------\n\n");
// 	print_index(&stack2);

// 	free_list(&stack);
// 	free_list(&stack2);
// 	return (0);
// }
