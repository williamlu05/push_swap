/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:17:59 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/24 17:38:16 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "ft_printf.h"

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

# define S_SIMPLE 0
# define S_MEDIUM 1
# define S_COMPLEX 2
# define S_ADAPTIVE 3

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
	int		counts[11];
}	t_ps;

typedef struct s_opts
{
	int	strategy;
	int	bench;
	int	first;
}	t_opts;

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

int		ft_atoi(const char *str, int *err);
double	ft_disorder_index(t_list *stack);
int		dup_controller(t_list *stack);
t_list	*ft_newlst(int content);
int		ft_sizelst(t_list *lst);

void	init_ps(t_ps *ps);
void	lstadd_back(t_list **stack, t_list *new);
void	free_stack(t_list **stack);
void	error_exit(t_ps *ps);
void	build_stack(t_ps *ps, char **argv, int start);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_sorted(t_list *stack);

int		parse_opts(int argc, char **argv, t_opts *opts);
void	run_strategy(t_ps *ps, t_opts *opts, double disorder);
void	adaptive_sort(t_ps *ps, double disorder);
char	*strategy_name(int strategy, double disorder);
void	print_summary(t_ps *ps, double disorder, char *name);

int		small_sort(t_ps *ps, int n);
void	sort_three(t_ps *ps);
void	sort_five(t_ps *ps);

void	bubble(t_ps *ps);
void	radix_sort(t_ps *ps);

void	chunk_sort(t_ps *ps);
void	assign_index(t_list *stack);
int		isqrt(int n);
int		max_index_pos(t_list *b, int n, int k);

#endif
