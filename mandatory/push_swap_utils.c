/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 14:58:49 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 13:14:02 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

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

int	stack_length(t_stack *stack_a)
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

int	check_sorted(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}

t_stack	*find_highest(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*highest;

	if (!stack)
		return (NULL);
	temp = stack;
	highest = stack;
	while (temp)
	{
		if (highest->numbered < temp->numbered)
			highest = temp;
		temp = temp->next;
	}
	return (highest);
}
