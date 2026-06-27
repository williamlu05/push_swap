/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:03:02 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/08 20:30:21 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Writes signed hex number at file descriptor 'fd', ret -1 if failed
int	ft_putnbr_base16_fd(unsigned long n, int fd, char base)
{
	int		result;
	int		temp;

	result = 0;
	if (n < 16)
		return (ft_putchar_fd(write_base16(n, base), fd));
	temp = ft_putnbr_base16_fd(n / 16, fd, base);
	if (temp < 0)
		return (-1);
	result = temp;
	temp = ft_putchar_fd(write_base16(n % 16, base), fd);
	if (temp < 0)
		return (-1);
	return (result + temp);
}

// Writes unsigned number at file descriptor 'fd', ret -1 if failed
int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int		result;
	int		temp;

	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	temp = ft_putnbr_unsigned_fd(n / 10, fd);
	if (temp < 0)
		return (-1);
	result = temp;
	temp = ft_putchar_fd((n % 10) + '0', fd);
	if (temp < 0)
		return (-1);
	return (result + temp);
}

int	base_cases(int *n, int fd)
{
	int	result;

	result = 0;
	if (*n < 0)
	{
		*n = -1 * (*n);
		result += ft_putchar_fd('-', fd);
		if (result < 0)
			return (-1);
	}
	if (*n < 10)
	{
		result += ft_putchar_fd(*n + '0', fd);
		if (result < 0)
			return (-1);
	}
	return (result);
}

// Writes signed number at file descriptor 'fd', ret -1 if failed
int	ft_putnbr_fd(int n, int fd)
{
	int		result;
	int		temp;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	temp = base_cases(&n, fd);
	if (temp < 0)
		return (-1);
	if (temp > 0 && n < 10)
		return (temp);
	result = temp;
	temp = ft_putnbr_fd(n / 10, fd);
	if (temp < 0)
		return (-1);
	result += temp;
	temp = ft_putchar_fd((n % 10) + '0', fd);
	if (temp < 0)
		return (-1);
	return (result + temp);
}
