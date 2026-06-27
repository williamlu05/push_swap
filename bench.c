/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:57:53 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/06/27 17:57:55 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	bp;

	bp = (int)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(bp / 100, 2);
	ft_putstr_fd(".", 2);
	if (bp % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(bp % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_counts_a(t_ps *ps)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ps->counts[OP_SA], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ps->counts[OP_SB], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ps->counts[OP_SS], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ps->counts[OP_PA], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ps->counts[OP_PB], 2);
	ft_putstr_fd("\n", 2);
}

static void	print_counts_b(t_ps *ps)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ps->counts[OP_RA], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ps->counts[OP_RB], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ps->counts[OP_RR], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ps->counts[OP_RRA], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ps->counts[OP_RRB], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ps->counts[OP_RRR], 2);
	ft_putstr_fd("\n", 2);
}

void	print_summary(t_ps *ps, double disorder, char *name)
{
	int	i;
	int	total;

	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	i = 0;
	total = 0;
	while (i < 11)
		total += ps->counts[i++];
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_counts_a(ps);
	print_counts_b(ps);
}
