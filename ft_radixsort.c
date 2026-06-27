/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 17:58:33 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int n)
{
	int	max;
	int	bits;

	max = n - 1;
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_pass(t_ps *ps, int n, int bit)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (((ps->a->index >> bit) & 1) == 0)
			pb(ps);
		else
			ra(ps);
		i++;
	}
	while (ps->b)
		pa(ps);
}

void	radix_sort(t_ps *ps)
{
	int	n;
	int	bits;
	int	bit;

	if (!ps || !ps->a)
		return ;
	n = ft_sizelst(ps->a);
	if (n <= 1)
		return ;
	assign_index(ps->a);
	bits = count_bits(n);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(ps, n, bit);
		bit++;
	}
}
