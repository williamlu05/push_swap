/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:17:59 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/03 19:20:55 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int	num;
	struct	s_list *next;
	struct	s_list *prev;
}	t_list;

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);

void	bubble(t_list **stack_a, t_list **stack_b);

int	ft_atoi(const char *str);
int	check_args(char *str);
int ft_disorder_index(t_list *stack);
int	dup_controller(t_list *stack);
t_list  *ft_newlst(int content);

void    mergesort(t_list **stack_a, t_list **stack_b);
void    merge_to_a(t_list **a, t_list **b, int ca, int cb);
void    merge_to_b(t_list **a, t_list **b, int ca, int cb);
int     ft_sizelst(t_list *lst);
#endif
