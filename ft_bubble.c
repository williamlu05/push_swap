/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:29:42 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/23 12:00:00 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sizelst(t_list *lst)
{
	t_list	*current;
	int		size;

	if (!lst)
		return (0);
	size = 1;
	current = lst;
	while (current->next != lst)
	{
		current = current->next;
		size++;
	}
	return (size);
}

static void	find_biggest(t_ps *ps, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ps->a->num > ps->a->next->num)
			sa(ps);
		ra(ps);
		i++;
	}
}

static void	restore_to_a(t_ps *ps)
{
	int	len;

	len = ft_sizelst(ps->b);
	while (len > 0)
	{
		rrb(ps);
		pa(ps);
		len--;
	}
}

void	bubble(t_ps *ps)
{
	int	len;

	if (!ps || !ps->a)
		return ;
	len = ft_sizelst(ps->a);
	while (len > 1)
	{
		find_biggest(ps, len);
		pb(ps);
		len--;
	}
	pb(ps);
	restore_to_a(ps);
}
