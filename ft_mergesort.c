/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/10 12:00:00 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b(t_list **a, t_list **b, int n);

static void	sort_a(t_list **a, t_list **b, int n)
{
	int	half;
	int	i;

	if (n <= 1)
		return ;
	if (n == 2)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a);
		return ;
	}
	half = n / 2;
	i = 0;
	while (i < half)
	{
		pb(b, a);
		i++;
	}
	sort_a(a, b, n - half);
	sort_b(a, b, half);
	merge_to_a(a, b, n - half, half);
}

static void	sort_b(t_list **a, t_list **b, int n)
{
	int	half;
	int	i;

	if (n <= 1)
		return ;
	if (n == 2)
	{
		if ((*b)->num > (*b)->next->num)
			sb(b);
		return ;
	}
	half = n / 2;
	i = 0;
	while (i < half)
	{
		pa(a, b);
		i++;
	}
	sort_a(a, b, half);
	sort_b(a, b, n - half);
	merge_to_b(a, b, half, n - half);
}

void	mergesort(t_list **stack_a, t_list **stack_b)
{
	int	n;

	if (!stack_a || !*stack_a)
		return ;
	n = ft_sizelst(*stack_a);
	if (n <= 1)
		return ;
	sort_a(stack_a, stack_b, n);
}
