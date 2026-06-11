/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:05:06 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/05 13:17:42 by antgarci         ###   ########.fr       */
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
	printf("rra\n");
}

void	rrb(t_list **b)
{
	ft_rev_rotate(b);
	printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	printf("rrr\n");
}
