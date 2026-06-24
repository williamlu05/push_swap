/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:18:24 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/23 18:58:24 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*detach_src(t_list **src)
{
	t_list	*node;

	node = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		*src = (*src)->next;
	}
	return (node);
}

static void	attach_dst(t_list **dst, t_list *node)
{
	if (!*dst)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *dst;
		node->prev = (*dst)->prev;
		(*dst)->prev->next = node;
		(*dst)->prev = node;
	}
	*dst = node;
}

static void	ft_push(t_list **dst, t_list **src)
{
	t_list	*node;

	if (!*src)
		return ;
	node = detach_src(src);
	attach_dst(dst, node);
}

void	pa(t_ps *ps)
{
	ft_push(&ps->a, &ps->b);
	ft_printf("pa\n");
	ps->counts[OP_PA]++;
}

void	pb(t_ps *ps)
{
	ft_push(&ps->b, &ps->a);
	ft_printf("pb\n");
	ps->counts[OP_PB]++;
}
