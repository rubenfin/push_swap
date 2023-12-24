/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 13:54:15 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/24 12:14:12 by rfinneru      ########   odam.nl         */
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
	temp->value = curr->value;
	curr->value = curr->next->value;
	curr->next->value = temp->value;
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
	temp->value = curr->value;
	curr->value = curr->next->value;
	curr->next->value = temp->value;
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
	// write(1, "pb\n", 3);
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
	// write(1, "ra\n", 3);
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

void	fill_stack_a(char **values, t_stack **stack_a, int i)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->next = NULL;
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

void	print_stack(t_stack *stack_a)
{
	while (stack_a != NULL)
	{
		printf("%d ", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("\n");
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

void	push_swap(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	char	**values;
	int		n;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	values = ft_split(argv[argc - 1], ' ');
	while (values[i])
	{
		fill_stack_a(values, &stack_a, i);
		i++;
	}
	printf("\n\n\nstack_a\n");
	if (stack_a && stack_a->value)
		print_stack(stack_a);
	printf("\nstack_b\n");
	if (stack_b && stack_b->value)
		print_stack(stack_b);
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
