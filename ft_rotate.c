/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:31:13 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 17:58:39 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list **a)
{
	if (!*a)
		return ;
	*a = (*a)->next;
}

void	ra(t_ps *ps)
{
	ft_rotate(&ps->a);
	ft_printf("ra\n");
	ps->counts[OP_RA]++;
}

void	rb(t_ps *ps)
{
	ft_rotate(&ps->b);
	ft_printf("rb\n");
	ps->counts[OP_RB]++;
}

void	rr(t_ps *ps)
{
	ft_rotate(&ps->a);
	ft_rotate(&ps->b);
	ft_printf("rr\n");
	ps->counts[OP_RR]++;
}
