/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:36:31 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 17:59:31 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_opts	opts;
	double	disorder;

	init_ps(&ps);
	if (parse_opts(argc, argv, &opts))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (opts.first >= argc)
		return (0);
	build_stack(&ps, argv, opts.first);
	disorder = ft_disorder_index(ps.a);
	if (!is_sorted(ps.a))
		run_strategy(&ps, &opts, disorder);
	if (opts.bench)
		print_summary(&ps, disorder, strategy_name(opts.strategy, disorder));
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}
