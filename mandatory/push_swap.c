/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 13:54:15 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 11:17:29 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_list(t_stack **stack_a, t_stack **stack_b)
{
	update_a_b_index(stack_a, stack_b);
	find_target(*stack_a, *stack_b);
	set_push_cost(*stack_a, *stack_b);
	find_cheapest(stack_a);
	push_cheapest(stack_a, stack_b);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	length_a;

	length_a = stack_length(*stack_a);
	if (length_a == 5)
		sort_stack_of_5(stack_a, stack_b);
	else if (length_a == 4)
	{
		push_lowest(stack_a, stack_b);
		sort_stack_of_3(stack_a);
		put_back(stack_a, stack_b);
		put_lowest_first(stack_a);
	}
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		while (stack_length(*stack_a))
			update_list(stack_a, stack_b);
		put_highest_first(stack_b);
		while (*stack_b)
			pa(stack_a, stack_b);
		return ;
	}
}

void	input_and_make_stack(int argc, char *argv[], t_stack **stack_a)
{
	int		i;
	char	**values;

	values = convert_input(argc, argv);
	i = -1;
	while (values[++i])
	{
		if (!fill_stack_a(values, stack_a, i))
		{
			free_stack(stack_a);
			free_values(values, 0);
			print_err_exit();
		}
	}
	free_values(values, 0);
}

void	push_swap(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	input_and_make_stack(argc, argv, &stack_a);
	get_numbered(&stack_a);
	index_median_curr_stack(&stack_a);
	if (!check_sorted(stack_a))
	{
		if (stack_length(stack_a) == 2)
			sa(&stack_a, 1);
		else if (stack_length(stack_a) == 3)
			sort_stack_of_3(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stacks(&stack_a, &stack_b);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
		push_swap(argc, argv);
	return (0);
}
