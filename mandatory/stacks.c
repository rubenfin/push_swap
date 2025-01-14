/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stacks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 13:13:06 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 14:20:41 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_of_5(t_stack **stack_a, t_stack **stack_b)
{
	index_median_curr_stack(stack_a);
	push_lowest(stack_a, stack_b);
	index_median_curr_stack(stack_a);
	push_lowest(stack_a, stack_b);
	sort_stack_of_3(stack_a);
	put_back(stack_a, stack_b);
	put_back(stack_a, stack_b);
	put_lowest_first(stack_a);
}

void	sort_stack_of_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = ((*stack_a)->numbered);
	second = ((*stack_a)->next->numbered);
	third = ((*stack_a)->next->next->numbered);
	if (first > second && first < third)
		sa(stack_a, 1);
	else if (first > second && first > third && third < second)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first > second && first > third && third > second)
		ra(stack_a, 1);
	else if (first < second && second > third && third > first)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, 1);
}

void	update_a_b_index(t_stack **a, t_stack **b)
{
	index_median_curr_stack(a);
	index_median_curr_stack(b);
}
