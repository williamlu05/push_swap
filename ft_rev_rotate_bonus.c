/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:05:06 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:44:22 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_rev_rotate(t_list **a)
{
	if (!*a)
		return ;
	*a = (*a)->prev;
}

void	rra(t_ps *ps)
{
	ft_rev_rotate(&ps->a);
}

void	rrb(t_ps *ps)
{
	ft_rev_rotate(&ps->b);
}

void	rrr(t_ps *ps)
{
	ft_rev_rotate(&ps->a);
	ft_rev_rotate(&ps->b);
}
