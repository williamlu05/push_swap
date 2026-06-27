/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 17:58:10 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_phase(t_ps *ps, int n, int chunk_size)
{
	int	max_idx;
	int	pushed;
	int	target;

	max_idx = chunk_size - 1;
	pushed = 0;
	while (pushed < n)
	{
		target = max_idx + 1;
		if (target > n)
			target = n;
		while (pushed < target)
		{
			if (ps->a->index <= max_idx)
			{
				pb(ps);
				pushed++;
			}
			else
				ra(ps);
		}
		max_idx += chunk_size;
	}
}

static void	ret_phase(t_ps *ps, int n, int k)
{
	int	size;
	int	pos;
	int	cnt;

	size = n;
	while (size > 0)
	{
		pos = max_index_pos(ps->b, size, k);
		cnt = size - pos;
		if (pos <= size / 2)
			while (pos-- > 0)
				rb(ps);
		else
			while (cnt-- > 0)
				rrb(ps);
		pa(ps);
		size--;
	}
}

void	chunk_sort(t_ps *ps)
{
	int	n;
	int	chunk_size;

	if (!ps || !ps->a)
		return ;
	n = ft_sizelst(ps->a);
	if (n <= 1)
		return ;
	assign_index(ps->a);
	chunk_size = isqrt(n);
	push_phase(ps, n, chunk_size);
	ret_phase(ps, n, chunk_size);
}
