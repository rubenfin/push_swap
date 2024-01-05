/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 13:54:15 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/05 16:53:59 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(char **values, t_stack **stack_a, int i)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->next = NULL;
	new_node->flag = false;
	new_node->index = 0;
	new_node->value = ft_atoi(values[i]);
	if (!*stack_a)
	{
		*stack_a = new_node;
		return ;
	}
	curr = *stack_a;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void	free_stack(t_stack *stack_a)
{
	t_stack	*temp;

	while (stack_a != NULL)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
}
int	check_stack_length(t_stack *stack_a)
{
	t_stack	*curr;
	int		length;

	length = 0;
	curr = stack_a;
	while (curr)
	{
		length++;
		curr = curr->next;
	}
	return (length);
}
void	get_highest_and_lowest(t_stack *stack, int *highest, int *lowest)
{
	while (stack)
	{
		if (*highest < stack->value)
			*highest = stack->value;
		if (*lowest > stack->value)
			*lowest = stack->value;
		stack = stack->next;
	}
}

void	push_first_two_num(t_stack **stack_a, t_stack **stack_b, int *highest,
		int *lowest)
{
	int	i;

	*highest = INT_MIN;
	*lowest = INT_MAX;
	i = 0;
	while (i++ < 2)
		pb(stack_a, stack_b);
	get_highest_and_lowest(*stack_b, highest, lowest);
	if ((*stack_b)->value != *highest)
		rb(stack_b);
}
void	go_to_last(t_stack **list)
{
	while ((*list)->next)
	{
		(*list) = (*list)->next;
	}
}

void	check_best_move(t_stack **stack_a, t_stack **stack_b, int *highest,
		int *lowest)
{
	int	a_value;
	int	counter;

	counter = 0;
	a_value = (*stack_a)->value;
	if (a_value > *highest)
	{
		*highest = a_value;
		pb(stack_a, stack_b);
	}
	if (a_value < *highest && a_value < *lowest)
	{
		*lowest = a_value;
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	if (a_value < *highest && a_value > *lowest)
	{
		while (a_value < (*stack_b)->value)
		{
			counter++;
			rb(stack_b);
		}
		pb(stack_a, stack_b);
		while (counter > 0)
		{
			rrb(stack_b);
			counter--;
		}
	}
}

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	highest;
	int	lowest;
	int	stack_length;

	stack_length = check_stack_length(*stack_a);
	push_first_two_num(stack_a, stack_b, &highest, &lowest);
	while (check_stack_length(*stack_a))
	{
		check_best_move(stack_a, stack_b, &highest, &lowest);
	}
	while (check_stack_length(*stack_b))
	{
		pa(stack_a, stack_b);
	}
}

void	sort_stack_of_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = ((*stack_a)->index);
	second = ((*stack_a)->next->index);
	third = ((*stack_a)->next->next->index);
	if (first > second && first < third)
		sa(stack_a);
	else if (first > second && first > third && third < second)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first > third && third > second)
		ra(stack_a);
	else if (first < second && second > third && third > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}
int	get_last_value(t_stack *temp)
{
	go_to_last(&temp);
	return (temp->value);
}

// void	push_2_to_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	while (check_stack_length(*stack_b))
// 	{
// 		if ((*stack_b)->value < (*stack_a)->value)
// 			pa(stack_a, stack_b);
// 		else if ((*stack_b)->value > (*stack_a)->value
// 			&& (*stack_b)->value > get_last_value(*stack_a))
// 		{
// 			ra(stack_a);
// 			pa(stack_a, stack_b);
// 			rra(stack_a);
// 		}
// 		else if ((*stack_b)->value > (*stack_a)->value
// 			&& (*stack_b)->value < get_last_value(*stack_a))
// 		{
// 			while ((*stack_b)->value(*stack_a)->value
// 				&& (*stack_b)->value > (*stack_a)->next->value)
// 			{
// 				ra(stack_a);
// 			}
// 			pa(stack_a, stack_b);
// 		}
// 	}
// }

void	change_stack_value(t_stack *stack_a)
{
	int		i;
	int		stack_length;
	t_stack	*lowest;
	t_stack	*temp;

	i = 1;
	stack_length = check_stack_length(stack_a);
	while (i < stack_length + 1)
	{
		temp = stack_a;
		while (temp->flag)
			temp = temp->next;
		lowest = temp;
		while (temp)
		{
			if (lowest->value > temp->value && !temp->flag)
				lowest = temp;
			temp = temp->next;
		}
		lowest->index = i;
		lowest->flag = true;
		i++;
	}
}

void	push_swap(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	char	**values;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	values = convert_input(argc, argv);
	while (values[i])
	{
		fill_stack_a(values, &stack_a, i);
		i++;
	}
	print_stack(stack_a);
	print_stack_index(stack_a);
	change_stack_value(stack_a);
	print_stack(stack_a);
	print_stack_index(stack_a);
	if (check_stack_length(stack_a) == 3)
	{
		sort_stack_of_3(&stack_a);
		print_stack(stack_a);
		exit(EXIT_SUCCESS);
	}
	// if (check_stack_length(stack_a) == 5)
	// {
	// 	pb(&stack_a, &stack_b);
	// 	pb(&stack_a, &stack_b);
	// 	sort_stack_of_3(&stack_a);
	// 	// push_2_to_a(&stack_a, &stack_b);
	// }
	// if (check_stack_length(stack_a) != 5 && check_stack_length(stack_a) != 3)
	// 	turk_algorithm(&stack_a, &stack_b);
	// print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	else
		push_swap(argc, argv);
	return (0);
}
