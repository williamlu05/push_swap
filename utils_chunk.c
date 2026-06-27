/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:00:11 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(t_list *stack, int value)
{
	t_list	*cur;
	int		cnt;

	cnt = 0;
	cur = stack;
	while (1)
	{
		if (cur->num < value)
			cnt++;
		cur = cur->next;
		if (cur == stack)
			break ;
	}
	return (cnt);
}

void	assign_index(t_list *stack)
{
	t_list	*cur;

	if (!stack)
		return ;
	cur = stack;
	while (1)
	{
		cur->index = count_smaller(stack, cur->num);
		cur = cur->next;
		if (cur == stack)
			break ;
	}
}

int	isqrt(int n)
{
	int	r;

	r = 1;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

static int	keep_max(t_list *node, int pos, int best, int *bpos)
{
	if (node->index > best)
	{
		*bpos = pos;
		return (node->index);
	}
	return (best);
}

int	max_index_pos(t_list *b, int n, int k)
{
	t_list	*cur;
	int		best;
	int		bpos;
	int		pos;

	bpos = 0;
	best = -1;
	cur = b;
	pos = 0;
	while (pos < n && pos < k)
	{
		best = keep_max(cur, pos, best, &bpos);
		cur = cur->next;
		pos++;
	}
	cur = b->prev;
	pos = n - 1;
	while (pos >= n - k && pos >= k)
	{
		best = keep_max(cur, pos, best, &bpos);
		cur = cur->prev;
		pos--;
	}
	return (bpos);
}
