/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:10:59 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/11 14:35:11 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sizelst(t_list *lst)
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

void    to_index(t_list **stack_a)
{
    t_list  *current;
    t_list  *compare;
    int     ind;
    int     i;
    int     j;

    i = 0;
    current = (*stack_a);
    while(i < ft_sizelst(*stack_a))
    {
        compare = (*stack_a);
        ind = 0;
        j = 0;
        while(j < ft_sizelst(*stack_a))
        {
            if(current->num > compare->num)
                ind++;
            j++;
            compare = compare->next;
        }
        i++;
        current->index = ind;
        current = current->next;
    }
}