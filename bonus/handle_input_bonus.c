/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_input_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 14:58:38 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 10:36:43 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	*make_and_fill_int_arr(char **values)
{
	long	*matrix;
	int		length;
	int		i;

	length = 0;
	while (values[length])
		length++;
	matrix = (long *)malloc(length * sizeof(long));
	if (!matrix)
		return (0);
	i = -1;
	while (++i < length)
	{
		if (ft_atoi_bonus(values[i]) > INT_MAX
			|| ft_atoi_bonus(values[i]) < INT_MIN)
			return (free(matrix), NULL);
		matrix[i] = ft_atoi_bonus(values[i]);
	}
	return (matrix);
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
	new_node->flag = false;
	new_node->numbered = 0;
	new_node->value = ft_atoi_bonus(values[i]);
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
