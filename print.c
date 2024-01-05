/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/05 16:31:09 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/05 16:38:56 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a)
{
	printf("-------------\n");
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("-------------");
	printf("\n");
}

void	print_stack_index(t_stack *stack_a)
{
	printf("-------------\n");
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->index);
		stack_a = stack_a->next;
	}
	printf("-------------\n");
	;
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("-------------\n");
	printf("stack_a\n");
	if (stack_a && stack_a->value)
		print_stack(stack_a);
	printf("\nstack_b\n");
	if (stack_b && stack_b->value)
		print_stack(stack_b);
	printf("-------------\n");
}

void	print_stacks_index(t_stack *stack_a, t_stack *stack_b)
{
	printf("-------------\n");
	printf("\nstack_a -> index\n");
	if (stack_a && stack_a->index)
		print_stack(stack_a);
	printf("\nstack_b -> index\n");
	if (stack_b && stack_b->index)
		print_stack(stack_b);
	printf("-------------\n");
}
