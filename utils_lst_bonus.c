/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:48:22 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list	*ft_newlst(int content)
{
	t_list	*n1;

	n1 = malloc(sizeof(t_list));
	if (!n1)
		return (NULL);
	n1->num = content;
	n1->index = 0;
	n1->next = NULL;
	n1->prev = NULL;
	return (n1);
}

void	lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		new->next = new;
		new->prev = new;
		*stack = new;
		return ;
	}
	last = (*stack)->prev;
	last->next = new;
	new->prev = last;
	new->next = *stack;
	(*stack)->prev = new;
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next_n;

	if (!stack || !*stack)
		return ;
	(*stack)->prev->next = NULL;
	current = *stack;
	while (current)
	{
		next_n = current->next;
		free(current);
		current = next_n;
	}
	*stack = NULL;
}
