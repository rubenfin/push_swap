/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/31 14:06:03 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/05 17:07:15 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*curr;
	t_stack	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	curr = *stack_a;
	temp = malloc(sizeof(t_stack));
	if (!temp)
		exit(EXIT_FAILURE);
	temp = curr;
	curr = curr->next;
	curr->next = temp;
	free(temp);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*curr;
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	curr = *stack_b;
	temp = malloc(sizeof(t_stack));
	if (!temp)
		exit(EXIT_FAILURE);
	temp = curr;
	curr = curr->next;
	curr->next = temp;
	free(temp);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_b) || !(*stack_b)->value)
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

	if (!(*stack_a) || !(*stack_a)->value)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next)
	{
		last = last->next;
	}
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*first;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next)
	{
		last = last->next;
	}
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*save;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	save = NULL;
	while (last->next->next)
	{
		last = last->next;
	}
	save = last->next;
	last->next = NULL;
	save->next = *stack_a;
	*stack_a = save;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
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
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
