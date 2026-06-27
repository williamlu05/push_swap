/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:00:18 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	drain_a(t_ps *ps, int ca, int cb)
{
	while (ca > 0)
	{
		ra(ps);
		ca--;
	}
	while (cb > 0)
	{
		pa(ps);
		ra(ps);
		cb--;
	}
}

void	merge_to_a(t_ps *ps, int ca, int cb)
{
	int	total;

	total = ca + cb;
	while (ca > 0 && cb > 0)
	{
		if (ps->a->num <= ps->b->num)
		{
			ra(ps);
			ca--;
		}
		else
		{
			pa(ps);
			ra(ps);
			cb--;
		}
	}
	drain_a(ps, ca, cb);
	while (total > 0)
	{
		rra(ps);
		total--;
	}
}

static void	drain_b(t_ps *ps, int ca, int cb)
{
	while (cb > 0)
	{
		rb(ps);
		cb--;
	}
	while (ca > 0)
	{
		pb(ps);
		rb(ps);
		ca--;
	}
}

void	merge_to_b(t_ps *ps, int ca, int cb)
{
	int	total;

	total = ca + cb;
	while (ca > 0 && cb > 0)
	{
		if (ps->b->num <= ps->a->num)
		{
			rb(ps);
			cb--;
		}
		else
		{
			pb(ps);
			rb(ps);
			ca--;
		}
	}
	drain_b(ps, ca, cb);
	while (total > 0)
	{
		rrb(ps);
		total--;
	}
}
