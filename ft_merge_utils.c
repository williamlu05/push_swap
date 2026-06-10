/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/10 12:00:00 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	drain_a(t_list **a, t_list **b, int ca, int cb)
{
	while (ca > 0)
	{
		ra(a);
		ca--;
	}
	while (cb > 0)
	{
		pa(a, b);
		ra(a);
		cb--;
	}
}

void	merge_to_a(t_list **a, t_list **b, int ca, int cb)
{
	int	total;

	total = ca + cb;
	while (ca > 0 && cb > 0)
	{
		if ((*a)->num <= (*b)->num)
		{
			ra(a);
			ca--;
		}
		else
		{
			pa(a, b);
			ra(a);
			cb--;
		}
	}
	drain_a(a, b, ca, cb);
	while (total > 0)
	{
		rra(a);
		total--;
	}
}

static void	drain_b(t_list **a, t_list **b, int ca, int cb)
{
	while (cb > 0)
	{
		rb(b);
		cb--;
	}
	while (ca > 0)
	{
		pb(b, a);
		rb(b);
		ca--;
	}
}

void	merge_to_b(t_list **a, t_list **b, int ca, int cb)
{
	int	total;

	total = ca + cb;
	while (ca > 0 && cb > 0)
	{
		if ((*b)->num <= (*a)->num)
		{
			rb(b);
			cb--;
		}
		else
		{
			pb(b, a);
			rb(b);
			ca--;
		}
	}
	drain_b(a, b, ca, cb);
	while (total > 0)
	{
		rrb(b);
		total--;
	}
}
