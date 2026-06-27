/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 17:58:03 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_flag(t_opts *opts, char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		opts->strategy = S_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		opts->strategy = S_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		opts->strategy = S_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		opts->strategy = S_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		opts->bench = 1;
	else
		return (1);
	return (0);
}

int	parse_opts(int argc, char **argv, t_opts *opts)
{
	int	i;

	opts->strategy = S_ADAPTIVE;
	opts->bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (set_flag(opts, argv[i]))
			return (1);
		i++;
	}
	opts->first = i;
	return (0);
}
