/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:05:06 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 17:58:36 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_list **a)
{
	if (!*a)
		return ;
	*a = (*a)->prev;
}

void	rra(t_ps *ps)
{
	ft_rev_rotate(&ps->a);
	ft_printf("rra\n");
	ps->counts[OP_RRA]++;
}

void	rrb(t_ps *ps)
{
	ft_rev_rotate(&ps->b);
	ft_printf("rrb\n");
	ps->counts[OP_RRB]++;
}

void	rrr(t_ps *ps)
{
	ft_rev_rotate(&ps->a);
	ft_rev_rotate(&ps->b);
	ft_printf("rrr\n");
	ps->counts[OP_RRR]++;
}
