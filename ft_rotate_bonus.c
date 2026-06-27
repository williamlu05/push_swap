/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:31:13 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:44:24 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_rotate(t_list **a)
{
	if (!*a)
		return ;
	*a = (*a)->next;
}

void	ra(t_ps *ps)
{
	ft_rotate(&ps->a);
}

void	rb(t_ps *ps)
{
	ft_rotate(&ps->b);
}

void	rr(t_ps *ps)
{
	ft_rotate(&ps->a);
	ft_rotate(&ps->b);
}
