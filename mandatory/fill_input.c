/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 10:47:58 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/09 14:01:59 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_median_curr_stack(t_stack **stack)
{
	t_stack	*temp;
	int		length;
	int		median;
	int		i;

	if (!*stack)
		return ;
	temp = *stack;
	length = stack_length(*stack);
	median = length / 2;
	i = 0;
	while (temp)
	{
		temp->push_cost = 0;
		temp->target_node = NULL;
		temp->cheapest = false;
		temp->stack_index = i;
		temp->above_median = (i < median);
		temp = temp->next;
		i++;
	}
}

void	get_numbered(t_stack **stack_a)
{
	int		i;
	int		length;
	t_stack	*lowest;
	t_stack	*temp;

	i = 1;
	length = stack_length((*stack_a));
	while (i < length + 1)
	{
		temp = (*stack_a);
		while (temp->flag)
			temp = temp->next;
		lowest = temp;
		while (temp)
		{
			if (lowest->value > temp->value && !temp->flag)
				lowest = temp;
			temp = temp->next;
		}
		lowest->numbered = i;
		lowest->flag = true;
		i++;
	}
}
