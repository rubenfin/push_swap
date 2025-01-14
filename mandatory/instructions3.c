/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions3.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 13:19:13 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 13:19:34 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, size_t print)
{
	t_stack	*last;
	t_stack	*save;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next->next)
	{
		last = last->next;
	}
	save = last->next;
	last->next = NULL;
	save->next = *stack_a;
	*stack_a = save;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, size_t print)
{
	t_stack	*last;
	t_stack	*save;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	save = NULL;
	while (last->next->next)
	{
		last = last->next;
	}
	save = last->next;
	last->next = NULL;
	save->next = *stack_b;
	*stack_b = save;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, size_t print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
