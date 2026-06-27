/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:00:05 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a->num;
	b = ps->a->next->num;
	c = ps->a->next->next->num;
	if (a > b && a < c)
		sa(ps);
	else if (a > b && b > c)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > b)
		ra(ps);
	else if (b > c && a < c)
	{
		sa(ps);
		ra(ps);
	}
	else if (b > c)
		rra(ps);
}

static int	min_pos(t_list *a, int n)
{
	t_list	*cur;
	int		pos;
	int		best;
	int		bpos;

	cur = a;
	best = a->num;
	bpos = 0;
	pos = 0;
	while (pos < n)
	{
		if (cur->num < best)
		{
			best = cur->num;
			bpos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (bpos);
}

static void	push_min(t_ps *ps, int n)
{
	int	pos;

	pos = min_pos(ps->a, n);
	if (pos <= n / 2)
		while (pos-- > 0)
			ra(ps);
	else
		while (pos++ < n)
			rra(ps);
	pb(ps);
}

void	sort_five(t_ps *ps)
{
	int	n;
	int	pushed;

	n = ft_sizelst(ps->a);
	pushed = 0;
	while (n > 3)
	{
		push_min(ps, n);
		n--;
		pushed++;
	}
	sort_three(ps);
	while (pushed-- > 0)
		pa(ps);
}

int	small_sort(t_ps *ps, int n)
{
	if (n <= 1)
		return (1);
	if (n == 2)
	{
		if (ps->a->num > ps->a->next->num)
			sa(ps);
		return (1);
	}
	if (n == 3)
	{
		sort_three(ps);
		return (1);
	}
	if (n <= 5)
	{
		sort_five(ps);
		return (1);
	}
	return (0);
}
