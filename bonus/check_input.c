/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 10:35:51 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 10:36:48 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_doubles(char **values)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = -1;
	x = 0;
	while (values[i])
	{
		j = i + 1;
		while (values[j])
		{
			if (!ft_strcmp(values[i], values[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_integers(char **values)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (values[i])
	{
		j = 0;
		while (values[i][j])
		{
			if (((!ft_isnum(values[i][j])) && (values[i][j] != '-'))
				|| ((values[i][j] == '-') && (!ft_isnum(values[i][j + 1])
						|| !values[i][j + 1])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
