/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:46:55 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/06/27 18:46:08 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	try_shift(t_ps *ps, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa(ps);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(ps);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(ps);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(ps);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(ps);
	else
		return (0);
	return (1);
}

static int	try_rotate(t_ps *ps, char *line)
{
	if (!ft_strncmp(line, "ra\n", 4))
		ra(ps);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(ps);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(ps);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(ps);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(ps);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(ps);
	else
		return (0);
	return (1);
}

static void	free_lines(void)
{
	char	*rest;

	rest = get_next_line(0);
	while (rest)
	{
		free(rest);
		rest = get_next_line(0);
	}
}

void	choose_movement(t_ps *ps, char *line)
{
	if (try_shift(ps, line) || try_rotate(ps, line))
		return ;
	free(line);
	free_lines();
	error_exit(ps);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	char	*line;

	if (argc < 2)
		return (0);
	init_ps(&ps);
	build_stack(&ps, argv, 1);
	line = get_next_line(0);
	while (line)
	{
		choose_movement(&ps, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(ps.a) && !ps.b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}
