/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:32:37 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 17:58:44 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list **stack)
{
	t_list	*a;
	t_list	*b;
	t_list	*last;
	t_list	*c;

	if (!(*stack) || (*stack)->next == *stack)
		return ;
	if ((*stack)->next->next == *stack)
	{
		*stack = (*stack)->next;
		return ;
	}
	a = *stack;
	b = a->next;
	last = a->prev;
	c = b->next;
	last->next = b;
	b->prev = last;
	b->next = a;
	a->prev = b;
	a->next = c;
	c->prev = a;
	*stack = b;
}

void	sa(t_ps *ps)
{
	ft_swap(&ps->a);
	ft_printf("sa\n");
	ps->counts[OP_SA]++;
}

void	sb(t_ps *ps)
{
	ft_swap(&ps->b);
	ft_printf("sb\n");
	ps->counts[OP_SB]++;
}

void	ss(t_ps *ps)
{
	ft_swap(&ps->a);
	ft_swap(&ps->b);
	ft_printf("ss\n");
	ps->counts[OP_SS]++;
}
