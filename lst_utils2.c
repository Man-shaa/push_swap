/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:13:35 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/03 15:12:41 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_list *prev_node, void *content)
{
	t_list	*node;

	if (!prev_node)
		return ;
	node = malloc(sizeof(t_list));
	node->content = content;
	node->next = prev_node->next;
	prev_node->next = node;
}

void	insert_last(t_list **lst, void	*content)
{
	t_list	*node;
	t_list	*last;

	node = ft_lstnew(content);
	last = ft_lstlast(*lst);
	last->next = node;
	node->next = NULL;
}

void	delete_node(t_list **lst, void *content)
{
	t_list	*prev;
	t_list	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	prev = (*lst);
	if (prev->content == content)
	{
		*lst = (*lst)->next;
		free(prev);
		return ;
	}
	while (tmp->content != content && tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->content == content)
	{
		prev->next = tmp->next;
		free(tmp);
	}
}

t_list	*find_elem(t_list *lst, void *val)
{
	t_list	*search;

	if (!lst)
		return (NULL);
	search = lst;
	lst = lst->next;
	while (search->content != val && lst)
	{
		search = lst;
		lst = lst->next;
	}
	if (search->content == val)
		return (search);
	return (NULL);
}

t_list	*find_prev_elem(t_list *lst, void *val)
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
