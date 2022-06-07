/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:00:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/07 17:53:17 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

t_list	*find_elem(t_list *lst, int val);
t_list	*find_prev_elem(t_list *lst, int val);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	insert_last(t_list **lst, int val);
void	insert_node(t_list *prev_node, int val);
void	delete_node(t_list **lst, int content);

t_list	*ft_lstnew(int val);
size_t	ft_lstsize(t_list *lst);
void	push(t_list **lst, int val);
t_list	*ft_lstlast(t_list *lst);
void	free_list(t_list **lst);

void	push_stack(t_list **stack1, t_list **stack2);
void	swap_stack(t_list *stack);
void	reverse_rotate_stack(t_list **stack);
void	sort_small(t_list **lst);
void	rotate_stack(t_list **stack);

void	indexing(t_list *list);
int		get_max_bits(t_list *lst);

int		is_sort(t_list	*lst);
int		ft_atoi(char *str);
int		is_arg_valid(char **str);
t_list	*init_list(int ac, char **av);
int		parsing(t_list *stack);

void	print_list(t_list **lst);
void	print_index(t_list **lst);

void	radix_sort(t_list **stack_a, t_list **stack_b);

#endif