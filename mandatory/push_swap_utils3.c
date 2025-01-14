/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils3.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 13:01:04 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 14:20:02 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_lowest(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*lowest;

	if (!stack)
		return (NULL);
	temp = stack;
	lowest = stack;
	while (temp)
	{
		if (lowest->value > temp->value)
			lowest = temp;
		temp = temp->next;
	}
	return (lowest);
}

void	above_median_check(t_stack *found, t_stack **stack_a, t_stack **stack_b)
{
	index_median_curr_stack(stack_a);
	if (found->above_median)
	{
		while (found != *stack_a)
			ra(stack_a, 1);
		pa(stack_a, stack_b);
	}
	else
	{
		while (found != *stack_a)
			rra(stack_a, 1);
		pa(stack_a, stack_b);
	}
}

void	push_lowest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack;

	stack = find_lowest(*stack_a);
	if (stack->above_median)
	{
		while (stack != *stack_a)
			ra(stack_a, 1);
	}
	else
	{
		while (stack != *stack_a)
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b);
}

void	put_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*search;
	t_stack	*save;

	search = *stack_a;
	save = NULL;
	while (search)
	{
		if (search->value > (*stack_b)->value)
		{
			if (save)
			{
				if (search->value < save->value)
					save = search;
			}
			else
				save = search;
		}
		search = search->next;
	}
	if (!save)
		save = find_lowest(*stack_a);
	above_median_check(save, stack_a, stack_b);
}
