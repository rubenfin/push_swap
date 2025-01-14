/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 10:53:01 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 12:59:00 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_lowest_first(t_stack **stack_a)
{
	t_stack	*lowest;

	if (!stack_a || !*stack_a)
		return ;
	lowest = find_lowest(*stack_a);
	index_median_curr_stack(stack_a);
	if (lowest->above_median)
	{
		while (lowest != *stack_a)
			ra(stack_a, 1);
	}
	else
	{
		while (lowest != *stack_a)
			rra(stack_a, 1);
	}
}

void	put_highest_first(t_stack **stack)
{
	t_stack	*highest;

	highest = find_highest(*stack);
	index_median_curr_stack(stack);
	if (highest->above_median)
	{
		while (highest != *stack)
			rb(stack, 1);
	}
	else
	{
		while (highest != *stack)
			rrb(stack, 1);
	}
}

void	go_to_last(t_stack **list)
{
	while ((*list)->next)
	{
		(*list) = (*list)->next;
	}
}

int	get_last_value(t_stack *temp)
{
	t_stack	*curr;

	curr = temp;
	if (!curr)
		return (0);
	go_to_last(&curr);
	return (curr->value);
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
