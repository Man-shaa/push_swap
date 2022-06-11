/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:13:35 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/11 15:56:44 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_last(t_list **lst, int val, int index)
{
	t_list	*node;
	t_list	*last;

	node = ft_lstnew(val, index);
	last = ft_lstlast(*lst);
	last->next = node;
	node->next = NULL;
}

void	delete_node(t_list **lst, int val)
{
	t_list	*prev;
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	prev = (*lst);
	if (prev->content == val)
	{
		*lst = (*lst)->next;
		free(prev);
		return ;
	}
	while (tmp->content != val && tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->content == val)
	{
		prev->next = tmp->next;
		free(tmp);
	}
}

t_list	*find_prev_elem(t_list *lst, int val)
{
	t_list	*search;
	t_list	*before;

	if (!lst)
		return (NULL);
	before = lst;
	search = lst->next;
	while (before->content != val && search->content != val && search)
	{
		before = search;
		search = search->next;
	}
	if (search->content == val || before->content == val)
		return (before);
	return (NULL);
}

t_list	*init_list(int ac, char **av)
{
	t_list	*stack;
	int		i;

	stack = ft_lstnew(ft_atoi(av[1]), 0);
	i = 2;
	while (i < ac)
	{
		insert_last(&stack, ft_atoi(av[i]), 0);
		i++;
	}
	indexing(stack);
	return (stack);
}
