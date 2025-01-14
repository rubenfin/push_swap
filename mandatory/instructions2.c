/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 15:35:56 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 13:19:31 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, size_t print)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = (*stack_a)->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, size_t print)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = (*stack_b)->next;
	last->next = first;
	first->next = NULL;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, size_t print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		write(1, "rr\n", 3);
}
