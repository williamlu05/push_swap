/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:29:42 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/03 19:06:31 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sizelst(t_list *lst)
{
    t_list  *last;
    t_list	*current;
	int		size;

	size = 0;
    last = lst->prev;
	current = lst;
	while (current != last)
	{
		current = current->next;
		size++;
	}
	return (size + 1);
}

void    bubble(t_list **stack_a, t_list **stack_b)
{
    int     len;
    int     i;

    len = ft_sizelst(*stack_a);
    while (len > 1)
    {
        i = 0;
        while (i < len)
        {
            if ((*stack_a)->num > (*stack_a)->next->num)
                sa(stack_a);
            ra(stack_a);
            i++;
        }
        pb(stack_b, stack_a);
        len--;
    }
    pb(stack_b, stack_a);
    len = ft_sizelst(*stack_b);
    while (len > 0)
    {
        rrb(stack_b);
        pb(stack_a, stack_b);
        len--;
    }
}