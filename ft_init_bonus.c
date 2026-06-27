/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:44:11 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	init_ps(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
}

void	error_exit(t_ps *ps)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(&ps->a);
	free_stack(&ps->b);
	exit(1);
}

int	dup_controller(t_list *stack)
{
	t_list	*current;
	t_list	*checker;

	current = stack;
	while (current->next != stack)
	{
		checker = current->next;
		while (checker != stack)
		{
			if (checker->num == current->num)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

void	build_stack(t_ps *ps, char **argv, int start)
{
	int	i;
	int	val;
	int	err;

	i = start;
	while (argv[i])
	{
		val = ft_atoi(argv[i], &err);
		if (err)
			error_exit(ps);
		lstadd_back(&ps->a, ft_newlst(val));
		i++;
	}
	if (ps->a && dup_controller(ps->a))
		error_exit(ps);
}
