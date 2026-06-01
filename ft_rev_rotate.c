/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:05:06 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 16:52:38 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_list **a)
{
	*a = (*a)->prev;
}

void	rra(t_list **a)
{
	ft_rev_rotate(a);
	write(1, "rra", 3);
}

void	rrb(t_list **b)
{
	ft_rev_rotate(b);
	write(1, "rrb", 3);
}

void	rrr(t_list **a, t_list **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	write(1, "rrr", 3);
}
