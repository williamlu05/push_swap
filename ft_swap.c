/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:32:37 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 17:00:43 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list **stack)
{	
	t_list *a;
	t_list *b;
	t_list *last;
	t_list *c;

	if (!*stack || (*stack)->next == *stack)
		return ;
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
	write(1,"sa", 2);
}

void	sb(t_list **b)
{
	ft_swap(b);
	write(1, "sb", 2);
}

void	ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss", 2);
}
