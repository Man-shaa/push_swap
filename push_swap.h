/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:10:16 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/15 01:50:18 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "stddef.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				cost;
	int				pos_in_a;
	struct s_stack	*next;
}				t_stack;

void		print_stack(t_stack *stack, char *name);

// big_sort.c
int			big_sort(t_stack **stack_a, t_stack **stack_b);
t_stack		*select_cheapest(t_stack *stack);
void		get_cheap_top_b(t_stack **stack_b, t_stack *cheap);
void		setup_a(t_stack **stack_a, int pos);

// cost.c
void		set_cost(t_stack *stack_a, t_stack *stack_b);
void		total_cost(t_stack *stack_a, t_stack *stack_b, t_stack *tmp);
int			cost_to_top_b(t_stack *stack, t_stack *tmp);
int			cost_setup_a(t_stack *stack, t_stack *tmp);

// create.c
t_stack		**create_stack(int ac, char **av, t_stack **stack);
t_stack		*ft_lstnew(int number);
int			add_last(t_stack **stack, int number);

// free.c
void		ft_free(void *addr);
void		free_list(t_stack **stack);
void		free_all(t_stack **stack_a, t_stack **stack_b);

// operations.c
void		push(t_stack **stack_1, t_stack **stack_b, char c);
void		rotate(t_stack **stack, char c);
void		rev_rotate(t_stack **stack, char c);
void		swap(t_stack **stack, char c);

// parsing.c
int			parsing(int ac, char **av);
int			check_only_numbers_and_int(int ac, char **av);
int			check_duplicate(int ac, char **av);
int			is_sorted(t_stack *stack);

// search_pos.c
int			a_sorted(t_stack *stack_a, t_stack *tmp);
void		first_part_before_min(t_stack *stack, t_stack *tmp);
void		find_pos_in_a(t_stack *stack_a, t_stack *tmp);

// setup_stack.c
int			set_up_stack(t_stack **stack_a, t_stack **stack_b);
void		keep_3_in_a(t_stack **stack_a, t_stack **stack_b);
void		indexing(t_stack *stack);
void		rearrange_stack_a(t_stack **stack_a);
void		reset_data(t_stack *stack);

// sort_small.c
void		sort_2(t_stack **stack, char c);
void		sort_3(t_stack **stack, char c);

// utils.c
int			ft_strlen(char *str);
int			err_msg(char *str, char *end, int ret);
long long	ft_atoi(char *str);
int			ft_lstsize(t_stack *stack);
t_stack		*ft_lstlast(t_stack *stack);

#endif