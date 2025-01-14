/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 14:02:52 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/09 15:52:22 by rfinneru      ########   odam.nl         */
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

	i = 0;
	j = -1;
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
		if (ft_atoi(values[i]) > INT_MAX || ft_atoi(values[i]) < INT_MIN)
			return (free(matrix), NULL);
		matrix[i] = ft_atoi(values[i]);
	}
	return (matrix);
}
