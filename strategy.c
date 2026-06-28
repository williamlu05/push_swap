/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:00:08 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_ps *ps, double disorder)
{
	if (disorder < 0.2)
		bubble(ps);
	else if (disorder < 0.5)
		chunk_sort(ps);
	else
		radix_sort(ps);
}

void	run_strategy(t_ps *ps, t_opts *opts, double disorder)
{
	if (small_sort(ps, ft_sizelst(ps->a)))
		return ;
	if (opts->strategy == S_SIMPLE)
		bubble(ps);
	else if (opts->strategy == S_MEDIUM)
		chunk_sort(ps);
	else if (opts->strategy == S_COMPLEX)
		radix_sort(ps);
	else
		adaptive_sort(ps, disorder);
}

static char	*adaptive_name(double disorder)
{
	if (disorder < 0.2)
		return ("Adaptive / O(n)");
	if (disorder < 0.5)
		return ("Adaptive / O(n\u221An)");
	return ("Adaptive / O(n log n)");
}

char	*strategy_name(int strategy, double disorder)
{
	if (strategy == S_SIMPLE)
		return ("Simple / O(n^2)");
	if (strategy == S_MEDIUM)
		return ("Medium / O\u221An)");
	if (strategy == S_COMPLEX)
		return ("Complex / O(n log n)");
	return (adaptive_name(disorder));
}
