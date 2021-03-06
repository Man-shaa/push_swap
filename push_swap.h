/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:00:25 by msharifi          #+#    #+#             */
/*   Updated: 2022/06/13 19:04:23 by msharifi         ###   ########.fr       */
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

void	delete_node(t_list **lst, int val);
t_list	*find_prev_elem(t_list *lst, int val);
void	insert_last(t_list **lst, int val, int index);
t_list	*init_list(int ac, char **av);

t_list	*ft_lstnew(int val, int index);
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	free_list(t_list **lst);

int		push_stack(t_list **stack1, t_list **stack2, char c);
int		swap_stack(t_list *stack, char c);
int		reverse_rotate_stack(t_list **stack, char c);
int		rotate_stack(t_list **stack, char c);

void	indexing(t_list *list);
int		find_index(t_list *stack, int x);
int		get_max_bits(t_list **lst);

int		is_sort(t_list	*lst);
int		is_int(char **str);
long	ft_atoi(char *str);
int		is_arg_valid(char **str);
int		find_duplicate(t_list *stack);

int		parse(int ac, char **av);
void	print_list(t_list **lst);
void	print_index(t_list **lst);
void	ft_putendl_fd(char *str, int fd);

void	radix_sort(t_list **stack_a, t_list **stack_b);

int		ss(t_list *stack_a, t_list *stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

void	sort_2(t_list **stack, char c);
void	sort_3(t_list **stack, char c);
void	sort_4(t_list **stack_a, t_list **stack_b, int x);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	sort_small(t_list **stack_a, t_list **stack_b);

#endif