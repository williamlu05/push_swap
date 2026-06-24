/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:35:43 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/08 19:33:16 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Returns char representation of 'n' of base letter 'start'
char	write_base16(unsigned long n, char start)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + start);
}

// Length of string 's'
int	ft_strlen(char *s)
{
	int	result;

	result = 0;
	while (*s++)
		result++;
	return (result);
}

// Writes string 's' at file descriptor 'fd', ret -1 if failed
int	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return (0);
	if (s == NULL)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

// Writes char at file descriptor 'fd', ret -1 if failed
int	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	return (write(fd, &c, 1));
}
