/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:32:37 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:44:25 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	sb(t_ps *ps)
{
	ft_swap(&ps->b);
}

void	ss(t_ps *ps)
{
	ft_swap(&ps->a);
	ft_swap(&ps->b);
}
