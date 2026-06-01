/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:18:24 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 16:48:22 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **dst, t_list **src)
{
    t_list *node;

    if (!*src)
        return ;
    node = *src;
    if ((*src)->next == *src)
        *src = NULL;
    else
    {
        (*src)->prev->next = (*src)->next;
        (*src)->next->prev = (*src)->prev;
        *src = (*src)->next;
    }
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

void	pa(t_list **a, t_list **b)
{
	ft_push(a, b);
	write(1, "pa", 2);
}

void	pb(t_list **b, t_list **a)
{
	ft_push(b, a);
	write(1, "pb", 2);
}
