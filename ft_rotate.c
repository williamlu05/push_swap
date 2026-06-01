/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:31:13 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 16:53:13 by antgarci         ###   ########.fr       */
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
	write(1, "ra", 2);
}

void	rb(t_list **b)
{
	ft_rotate(b);
	write(1, "rb", 2);
}

void	rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr", 3);
}
