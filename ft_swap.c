/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:32:37 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/03 18:57:25 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list **stack)
{	
	t_list *a;
	t_list *b;
	t_list *last;
	t_list *c;

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

void	sa(t_list **a)
{
	ft_swap(a);
	printf("sa\n");
}

void	sb(t_list **b)
{
	ft_swap(b);
	printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	printf("ss\n");
}
