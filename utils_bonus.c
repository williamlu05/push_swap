/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlu-bjor <wlu-bjor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:00:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/27 18:46:18 by wlu-bjor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_atoi(const char *str, int *err)
{
	long	num;
	int		i;
	int		sign;
	int		start;

	num = 0;
	i = 0;
	sign = 1;
	*err = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
		if ((sign == 1 && num > 2147483647) || (sign == -1 && num > 2147483648))
		{
			*err = 1;
			break ;
		}
	}
	if (i == start || str[i])
		*err = 1;
	return ((int)(num * sign));
}

// Returns 0 if two strings equals, difference of content of unequal
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_sorted(t_list *stack)
{
	t_list	*cur;

	if (!stack)
		return (1);
	cur = stack;
	while (cur->next != stack)
	{
		if (cur->num > cur->next->num)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return (0);
	if (s == NULL)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}
