/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:36:31 by antgarci          #+#    #+#             */
/*   Updated: 2026/06/01 19:37:02 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lstadd_front(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		new->next = new;
		new->prev = new;
		*stack = new;
		return ;
	}
	last = (*stack)->prev;
	(*stack)->prev = new;
	new->next = (*stack);
	last->next = new;
	new->prev = last;
	(*stack) = new;
}	

static void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next_n;

	if (!stack || !*stack)
		return ;
	(*stack)->prev->next = NULL;
	current = *stack;
	while (current)
	{
		next_n = current->next;
		free(current);
		current = next_n;
	}
	*stack = NULL;
}

static void	create_stack(t_list **stack_a, char **argv)
{
	int	i;

	*stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		if (!check_args(argv[i]))
		{
			printf("arg no valido\n");
			free_stack(stack_a);
			exit (1);
		}
		lstadd_front(stack_a, ft_lstnew(ft_atoi(argv[i++])));
	}
}

void	print_stack(t_list *stack, char c)
{
	t_list	*last;
	t_list	*current;
	int	content;

	if (!stack)
		return ;
	last = stack->prev;
	current = stack;
	content = 0;
	printf("lista %c:", c);
	while (current != last)
	{
		content = current->num;
		printf("%d ", content);
		current = current->next;	
	}
	printf("%d", current->num);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	create_stack(&stack_a, argv);

	printf("===I.DESORDEN===\n");
	ft_disorder_index(stack_a);

	printf("=== INICIAL ===\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');

	printf("\n=== sa ===\n");
	sa(&stack_a);
	write(1, "\n", 1);
	print_stack(stack_a, 'A');

	printf("\n=== ra ===\n");
	ra(&stack_a);
	write(1, "\n", 1);
	print_stack(stack_a, 'A');

	printf("\n=== rra ===\n");
	rra(&stack_a);
	write(1, "\n", 1);
	print_stack(stack_a, 'A');

	printf("\n=== pb (A -> B) ===\n");
	pb(&stack_b, &stack_a);
	write(1, "\n", 1);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');

	printf("\n=== pa (B -> A) ===\n");
	pa(&stack_a, &stack_b);
	write(1, "\n", 1);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');

	return (0);
}
