/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 13:05:37 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/09 15:42:53 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack_a)
{
	t_stack	*temp;

	while (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

void	free_values(char **values, int x)
{
	int	i;

	i = -1;
	if (x)
	{
		while (i < x)
		{
			if (values[++i])
				free(values[i]);
		}
	}
	else
	{
		if (values[0])
		{
			while (values[++i])
			{
				if (values[i])
					free(values[i]);
			}
		}
	}
	if (values)
		free(values);
}

void	print_err_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_values_matrix_exit(char **values, long *matrix)
{
	if (matrix)
		free(matrix);
	if (values)
		free_values(values, 0);
	print_err_exit();
}
