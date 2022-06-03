/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:08:38 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/03 15:57:41 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (0);
	element->content = content;
	element->next = 0;
	return (element);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	push(t_list **lst, void *x)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = x;
	new->next = *lst;
	*lst = new;
}

void	free_list(t_list **lst)
{
	t_list	*save;

	if (!*lst)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		free(*lst);
		*lst = save;
	}
}

void	print_list(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}
