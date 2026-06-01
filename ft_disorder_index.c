/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:25:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 19:51:42 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_disorder_index(t_list *stack)
{
	double	dis_index;
	int	mistakes;
	int	pairs;
	t_list	*current;

	mistakes = 0;
	pairs = 0;
	stack->prev->next = NULL;
	current = stack;
	printf("mistakes:%d\npairs:%d\n", mistakes, pairs);
	while (current->next->next != NULL)
	{
		if (current->num > current->next->num)
			mistakes++;
		current = current->next;
		pairs++;
		printf("mistakes:%d\npairs:%d\n", mistakes, pairs);
	}
	dis_index = mistakes / pairs;
	printf("%f\n", dis_index);
	return (dis_index);
}
