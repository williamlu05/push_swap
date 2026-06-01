/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:17:59 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 19:36:58 by antgarci         ###   ########.fr       */
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

int	check_args(char *str);
int	ft_atoi(const char *str);
int     ft_disorder_index(t_list *stack);
t_list  *ft_lstnew(int content);
#endif
