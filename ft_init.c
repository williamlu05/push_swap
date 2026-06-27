/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 20:34:08 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_ps(t_ps *ps)
{
	int	i;

	i = 0;
	ps->a = NULL;
	ps->b = NULL;
	while (i < 11)
		ps->counts[i++] = 0;
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

static int	is_string(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == 32)
		return (1);
		j++;
	}
	return (0);
}

void	build_stack(t_ps *ps, char **argv, int start)
{
	int	i;
	int	j;
	int	val;
	int	err;
	char	**str = NULL;
	
	i = start;
	while (argv[i])
	{
		if (is_string(argv[i]))
		{
			str = ft_split(argv[i], ' ');
			j = 0;
			while (str[j])
			{
				val = ft_atoi(str[j], &err);
				if (err)
					error_exit(ps);
				lstadd_back(&ps->a, ft_newlst(val));
				j++;
			}
			j = 0;
			while (str[j])
				free(str[j++]);
			free(str);
			i++;
		}
		val = ft_atoi(argv[i], &err);
		if (err)
			error_exit(ps);
		lstadd_back(&ps->a, ft_newlst(val));
		i++;
	}
	if (ps->a && dup_controller(ps->a))
		error_exit(ps);
}
