/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_input.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/05 13:50:40 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/05 14:50:04 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char c)
{
	return ((c >= 0 && c <= 9) || (c >= '0' && c <= '9'));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	*make_and_fill_int_arr(char **values)
{
	int	*matrix;
	int	length;
	int	i;

	length = 0;
	while (values[length])
		length++;
	matrix = (int *)malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		if (ft_atoi(values[i]) > INT_MAX || ft_atoi(values[i]) < INT_MIN)
		{
			write(1, "bigger than allowed values", 26);
			exit(EXIT_FAILURE);
		}
		matrix[i] = ft_atoi(values[i]);
		i++;
	}
	return (matrix);
}

void	check_all(char **values)
{
	int	*matrix;
	int	i;
	int	x;

	matrix = make_and_fill_int_arr(values);
	if (check_integers(values))
	{
		write(1, "integer Error\n", 14);
		exit(EXIT_FAILURE);
	}
	if (check_doubles(values))
	{
		write(1, "doubles Error\n", 15);
		exit(EXIT_FAILURE);
	}
	x = 0;
	while (values[x])
		x++;
	i = 0;
	while (i < x)
	{
		if (matrix[i] > INT_MAX || matrix[i] < INT_MIN)
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	check_int_decimal(int arg_int)
{
	int	counter;

	counter = 0;
	while (arg_int > 9)
	{
		counter++;
		arg_int /= 10;
	}
	return (counter);
}

char	**make_int_args_char(int argc, char *argv[])
{
	char	**values;
	int		i;
	int		x;

	x = 1;
	i = 0;
	values = (char **)malloc(argc * sizeof(char *));
	while (x < argc)
	{
		values[i] = malloc((ft_strlen(argv[x])) * sizeof(char));
		values[i] = argv[x];
		i++;
		x++;
	}
	return (values);
}

char	**convert_input(int argc, char *argv[])
{
	char **values;
	int total;

	if (argc == 2)
	{
		values = ft_split(argv[argc - 1], ' ');
		check_all(values);
	}
	if (argc > 2)
	{
		values = make_int_args_char(argc, argv);
		check_all(values);
	}
	total = 0;
	while (values[total])
		total++;
	if (total < 3)
	{
		write(1, "not enough arguments", 20);
		exit(EXIT_FAILURE);
	}
	return (values);
}