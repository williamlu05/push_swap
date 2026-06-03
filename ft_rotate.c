/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:31:13 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/03 18:57:49 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list **a)
{
	*a = (*a)->next;
}

void	ra(t_list **a)
{
	ft_rotate(a);
	printf("ra\n");
}

void	rb(t_list **b)
{
	ft_rotate(b);
	printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	printf("rr\n");
}
