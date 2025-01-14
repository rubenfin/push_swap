/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 14:44:06 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 10:49:26 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_in_instruction(t_stack **a, t_stack **b, char **instruction,
		char **total_instructions)
{
	free_stacks(a, b);
	if (*instruction)
		free(*instruction);
	if (*total_instructions)
		free(*total_instructions);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	do_instruction(t_stack **a, t_stack **b, char **instruction,
		char **total_instructions)
{
	if (!ft_strcmp(*instruction, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(*instruction, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(*instruction, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(*instruction, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(*instruction, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(*instruction, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(*instruction, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(*instruction, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(*instruction, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(*instruction, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(*instruction, "rrr\n"))
		rrr(a, b, 0);
	else
		error_in_instruction(a, b, instruction, total_instructions);
}

void	give_index(t_stack **a)
{
	int		i;
	int		length;
	t_stack	*lowest;
	t_stack	*temp;

	i = 1;
	length = stack_len((*a));
	while (i < length + 1)
	{
		temp = (*a);
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

int	check_index(t_stack *a, t_stack *b, int len)
{
	int	i;

	if (stack_len(a) != len || b)
		return (0);
	i = 1;
	while (a)
	{
		if (a->numbered != i)
			return (0);
		i++;
		a = a->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		input_and_make_stack(argc, argv, &a);
		give_index(&a);
		len = stack_len(a);
		read_instructions(&a, &b);
		if (check_index(a, b, len))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stacks(&a, &b);
	}
	return (0);
}
