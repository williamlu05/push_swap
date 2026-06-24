/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:19:04 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/08 20:12:27 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Writes all characters up to 'letter' and returns 
	the string 'format' pointed to the char after 'letter'
*/
int	interpret_conversion(char const *format, va_list *args)
{
	if (*format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	if (*format == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	if (*format == 'p')
		return (ft_putptr_fd(va_arg(*args, unsigned long), 1));
	if (*format == 'd')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	if (*format == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	if (*format == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(*args, unsigned int), 1));
	if (*format == 'x')
		return (ft_putnbr_base16_fd(va_arg(*args, unsigned int), 1, 'a'));
	if (*format == 'X')
		return (ft_putnbr_base16_fd(va_arg(*args, unsigned int), 1, 'A'));
	if (*format == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		written;
	int		conversion;

	if (!format)
		return (-1);
	written = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			conversion = interpret_conversion(++format, &args);
			if (conversion < 0)
				return (-1);
			written += conversion;
		}
		else
			written += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (written);
}
