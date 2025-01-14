/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/31 14:06:03 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 13:19:41 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, size_t print)
{
	t_stack	*curr;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	curr = *stack_a;
	*stack_a = curr->next;
	curr->next = (*stack_a)->next;
	(*stack_a)->next = curr;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, size_t print)
{
	t_stack	*curr;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	curr = *stack_b;
	*stack_b = curr->next;
	curr->next = (*stack_b)->next;
	(*stack_b)->next = curr;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, size_t print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}
