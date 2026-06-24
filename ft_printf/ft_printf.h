/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:47:04 by wlu-bjor          #+#    #+#             */
/*   Updated: 2026/05/04 22:47:04 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		interpret_conversion(char const *format, va_list *args);

char	write_base16(unsigned long n, char start);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);

int		ft_putnbr_base16_fd(unsigned long n, int fd, char base);
int		ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		ft_putnbr_fd(int n, int fd);

int		ft_putptr_fd(unsigned long n, int fd);
#endif