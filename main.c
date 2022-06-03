/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:12:08 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/03 16:03:45 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main()
{
	t_list	*stack;
	t_list	*stack2;

// initialisation stack 1
	stack = ft_lstnew((void *)"Bonjour");
	insert_last(&stack, (void *)"j'ai");
	insert_last(&stack, (void *)"faim");
	insert_last(&stack, (void *)"Au revoir");

// initialisation stack 2
	stack2 = ft_lstnew((void *)"Manuel");
	insert_last(&stack2, (void *)"Sharifi");

	printf("------- STACK 1 -------\n\n");
	print_list(&stack);
	printf("------- STACK 2 -------\n\n");
	print_list(&stack2);

	printf("\n++++++++ AFTER CHANGES ++++++++\n\n\n");

	printf("------- STACK 1 -------\n\n");
	print_list(&stack);
	printf("------- STACK 2 -------\n\n");
	print_list(&stack2);

	free_list(&stack);
	free_list(&stack2);
	return (0);
}