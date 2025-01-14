/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/05 13:50:40 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 10:28:00 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_all(char **values, int argc)
{
	long	*matrix;
	int		i;

	matrix = make_and_fill_int_arr(values);
	if (!matrix)
		free_values_matrix_exit(values, matrix);
	if (check_integers(values))
		free_values_matrix_exit(values, matrix);
	if (check_doubles(values))
		free_values_matrix_exit(values, matrix);
	i = -1;
	while (++i < argc - 1)
	{
		if (matrix[i] > INT_MAX || matrix[i] < INT_MIN)
			free_values_matrix_exit(values, matrix);
	}
	free(matrix);
}

char	**move_argv_to_values(int argc, char *argv[])
{
	char	**values;
	int		i;
	int		x;
	int		j;

	x = 1;
	i = 0;
	j = 0;
	values = (char **)malloc(argc * sizeof(char *));
	if (!values)
		return (NULL);
	while (x < argc)
	{
		j = -1;
		values[i] = (char *)malloc((ft_strlen(argv[x]) + 1) * sizeof(char));
		if (!values[i])
			return (free_values(values, i), NULL);
		while (argv[x][++j])
			values[i][j] = argv[x][j];
		values[i][j] = '\0';
		i++;
		x++;
	}
	values[i] = 0;
	return (values);
}

int	argv_check(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**convert_input(int argc, char *argv[])
{
	char	**values;

	if (argc == 2)
		values = ft_split(argv[argc - 1], ' ');
	else
	{
		if (!argv_check(argc, argv))
			print_err_exit();
		values = move_argv_to_values(argc, argv);
	}
	if (!values)
		print_err_exit();
	check_all(values, argc);
	return (values);
}

int	fill_stack_a(char **values, t_stack **stack_a, int i)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->target_node = NULL;
	new_node->flag = false;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->push_cost = 0;
	new_node->numbered = 0;
	new_node->stack_index = 0;
	new_node->value = ft_atoi(values[i]);
	if (!*stack_a)
	{
		*stack_a = new_node;
		return (1);
	}
	last_node = *stack_a;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	return (1);
}
