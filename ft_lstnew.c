/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:38:27 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 16:47:34 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*n1;

	n1 = malloc(sizeof(t_list));
	if (!n1)
		return (NULL);
	n1->num = content;
	n1->next = NULL;
	return (n1);
}
/*
int	main(void)
{
	t_list	*l1 = ft_lstnew("l1");
	printf("%s", (char *)l1->content);
	free(l1);
}
*/
