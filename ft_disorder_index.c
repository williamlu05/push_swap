/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:25:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 17:58:17 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_disorder_index(t_list *stack)
{
	t_list	*current;
	t_list	*other;
	double	mistakes;
	double	pairs;

	if (!stack)
		return (0);
	mistakes = 0;
	pairs = 0;
	current = stack;
	while (current->next != stack)
	{
		other = current->next;
		while (other != stack)
		{
			pairs++;
			if (current->num > other->num)
				mistakes++;
			other = other->next;
		}
		current = current->next;
	}
	if (pairs == 0)
		return (0);
	return (mistakes / pairs);
}
