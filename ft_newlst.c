/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:59:39 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/05 17:12:05 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newlst(int content)
{
	t_list	*n1;

	n1 = malloc(sizeof(t_list));
	if (!n1)
		return (NULL);
	n1->num = content;
	n1->next = NULL;
	n1->prev = NULL;
	n1->index = 0;
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
