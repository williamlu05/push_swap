/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/23 12:00:00 by antgarci         ###   ########.fr       */
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

int	max_index_pos(t_list *b, int n)
{
	t_list	*cur;
	int		pos;
	int		best;
	int		best_pos;

	cur = b;
	pos = 0;
	best = cur->index;
	best_pos = 0;
	while (pos < n)
	{
		if (cur->index > best)
		{
			best = cur->index;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best_pos);
}
