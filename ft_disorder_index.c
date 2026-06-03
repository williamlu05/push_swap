/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:25:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 20:25:03 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_disorder_index(t_list *stack)
{
	double	dis_index;
	double	mistakes;
	double	pairs;
	t_list	*current;
	t_list	*last;

	mistakes = 0;
	pairs = 0;
	last = stack->prev;
	last->next = NULL;
	current = stack;
	printf("%d", current->num);
	while (current->next != NULL)
	{
		if (current->num > current->next->num)
			mistakes++;
		pairs++;
		current = current->next;
		printf("mistakes:%f\npairs:%f\n", mistakes, pairs);
	}
	last->next = stack;
	if (pairs == 0)
		return(0);
	dis_index = mistakes / pairs;
	printf("%.2f\n", dis_index);
	return (dis_index);
}
