/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:00:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/02 18:07:48 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*find_elem(t_list *lst, void *val);
t_list	*find_prev_elem(t_list *lst, void *val);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	insert_last(t_list **lst, void	*content);
void	insert_node(t_list *prev_node, void *content);
void	delete_node(t_list **lst, void *content);

t_list	*ft_lstnew(void *content);
void	push(t_list **lst, void *x);
t_list	*ft_lstlast(t_list *lst);
void	print_list(t_list **lst);
void	free_list(t_list **lst);

void	push_stack(t_list **stack1, t_list **stack2);
void	swap_stack(t_list *stack);
int		parsing(t_list *lst);
void	reverse_rotate_stack(t_list **stack);
void	sort_small(t_list **lst);
void	rotate_stack(t_list **stack);

#endif