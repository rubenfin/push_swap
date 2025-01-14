/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 12:26:47 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 10:35:36 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	stack_len(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

int	ft_isnum(char c)
{
	return ((c >= 0 && c <= 9) || (c >= '0' && c <= '9'));
}
