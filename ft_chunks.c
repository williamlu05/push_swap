/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:57:26 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/11 15:42:44 by antgarci         ###   ########.fr       */
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

static int  chunk_selector(int size)
{
    if(size <= 100)
        return(5);
    if(size > 100 && size < 300)
        return(10);
    if(size >= 300)
        return(20);
    return (10);
}   

static void    chunk_arrange(t_list **stack_b)
{
    t_list *current;
    int     i;
    int     j;
    int     size;

    i = 0;
    size = ft_sizelst(*stack_b);
    current = (*stack_b);
    while(i < size - 1)
    {
        j = 0;
        while(j < size - 1)
        {
            if(current->num > current->next->num)
                sb(stack_b);
            current = current->next;
            j++;
        }
        i++;
    }
}

void    chunks_sort(t_list **stack_a, t_list **stack_b)
{
    int     size;
    int     chunk_size;
    int     curr_chunk;
    int     i;
    int     j;

    i = 0;
    size = ft_sizelst(*stack_a);
    chunk_size = chunk_selector(ft_sizelst(*stack_a));
    curr_chunk = chunk_size;
    while (i < size)
    {
        j = 0;
        while(j <= size)
        {
            printf("curr_chunk:%d\n", curr_chunk); 
            printf("j:%d index:%d num:%d\n", j, (*stack_a)->index, (*stack_a)->num);
            if(!*stack_a)
                break ;
            if((*stack_a)->index < curr_chunk)
            {
                pb(stack_b, stack_a);
                size--;
            }
            else
            {
                ra(stack_a);
                j++;
            }
        }
        curr_chunk += chunk_size;
        i += chunk_size;
        chunk_arrange(stack_b); 
    }
}