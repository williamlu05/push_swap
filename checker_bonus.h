/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:49:45 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/06/27 18:46:13 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_ps
{
	t_list	*a;
	t_list	*b;
}	t_ps;

void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);

void	init_ps(t_ps *ps);
void	build_stack(t_ps *ps, char **argv, int start);
int		dup_controller(t_list *stack);
void	error_exit(t_ps *ps);

int		ft_atoi(const char *str, int *err);
t_list	*ft_newlst(int content);

void	lstadd_back(t_list **stack, t_list *new);
void	free_stack(t_list **stack);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_sorted(t_list *stack);
int		ft_putstr_fd(char *s, int fd);

#endif