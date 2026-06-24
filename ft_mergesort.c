/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/23 12:00:00 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b(t_ps *ps, int n);

static void	sort_a(t_ps *ps, int n)
{
	int	half;
	int	i;

	if (n <= 1)
		return ;
	if (n == 2)
	{
		if (ps->a->num > ps->a->next->num)
			sa(ps);
		return ;
	}
	half = n / 2;
	i = 0;
	while (i < half)
	{
		pb(ps);
		i++;
	}
	sort_a(ps, n - half);
	sort_b(ps, half);
	merge_to_a(ps, n - half, half);
}

static void	sort_b(t_ps *ps, int n)
{
	int	half;
	int	i;

	if (n <= 1)
		return ;
	if (n == 2)
	{
		if (ps->b->num > ps->b->next->num)
			sb(ps);
		return ;
	}
	half = n / 2;
	i = 0;
	while (i < half)
	{
		pa(ps);
		i++;
	}
	sort_a(ps, half);
	sort_b(ps, n - half);
	merge_to_b(ps, half, n - half);
}

void	mergesort(t_ps *ps)
{
	int	n;

	if (!ps || !ps->a)
		return ;
	n = ft_sizelst(ps->a);
	if (n <= 1)
		return ;
	sort_a(ps, n);
}
