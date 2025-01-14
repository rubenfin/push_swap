/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_target.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 10:34:54 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 13:20:04 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_push_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	a_length;
	int	b_length;
	int	diverse;
	int	push_up;
	int	push_down;

	a_length = stack_length(stack_a);
	b_length = stack_length(stack_b);
	while (stack_a)
	{
		diverse = get_diverse(stack_a, a_length, b_length);
		push_up = find_max(stack_a->stack_index,
				stack_a->target_node->stack_index);
		push_down = find_max(a_length - stack_a->stack_index, b_length
				- stack_a->target_node->stack_index);
		if (diverse <= push_up && diverse <= push_down)
			stack_a->push_cost = diverse;
		else if (push_up < diverse && push_up < push_down)
			stack_a->push_cost = push_up;
		else
			stack_a->push_cost = push_down;
		stack_a = stack_a->next;
	}
}

void	find_cheapest(t_stack **stack_a)
{
	t_stack	*cheapest;
	t_stack	*current;

	cheapest = *stack_a;
	current = *stack_a;
	while (current)
	{
		current->cheapest = false;
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	cheapest->cheapest = true;
}

void	push_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*found;

	found = *stack_a;
	while (!found->cheapest)
		found = found->next;
	while (found->above_median && *stack_a != found
		&& found->target_node->above_median && *stack_b != found->target_node)
		rr(stack_a, stack_b, 1);
	while (!found->above_median && *stack_a != found
		&& !found->target_node->above_median && *stack_b != found->target_node)
		rrr(stack_a, stack_b, 1);
	while (found->above_median && *stack_a != found)
		ra(stack_a, 1);
	while (found->target_node->above_median && *stack_b != found->target_node)
		rb(stack_b, 1);
	while (!found->above_median && *stack_a != found)
		rra(stack_a, 1);
	while (!found->target_node->above_median && *stack_b != found->target_node)
		rrb(stack_b, 1);
	if (found == *stack_a && found->target_node == *stack_b)
		pb(stack_a, stack_b);
}

int	get_diverse(t_stack *stack_a, int a_length, int b_length)
{
	int	diverse;

	if (stack_a->above_median)
		diverse = stack_a->stack_index;
	else
		diverse = a_length - stack_a->stack_index;
	if (stack_a->target_node->above_median)
		diverse += stack_a->target_node->stack_index;
	else
		diverse += b_length - stack_a->target_node->stack_index;
	return (diverse);
}

void	find_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target;
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		target = stack_b;
		while (target)
		{
			if (target->value < current->value)
			{
				if (current->target_node)
				{
					if (target->value > current->target_node->value)
						current->target_node = target;
				}
				else
					current->target_node = target;
			}
			target = target->next;
		}
		if (!current->target_node)
			current->target_node = find_highest(stack_b);
		current = current->next;
	}
}
