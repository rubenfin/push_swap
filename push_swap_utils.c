/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 14:58:49 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/05 10:42:04 by rfinneru      ########   odam.nl         */
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

int	are_all_higher(t_stack *stack_a, t_stack *stack_b)
{
	int length = 0;
	t_stack *temp;
	while (stack_a->next)
	{
		temp = stack_b;
		while (temp->next)
		{
			if (stack_a->value < temp->value)
			{
				printf("not all values are higher %d < %d at length : %d \n", stack_a->value, temp->value, length);
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
		length++;
	}
	return(1);
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

