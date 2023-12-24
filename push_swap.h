/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 15:07:58 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/20 15:15:11 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// libft utils
void				ft_lstadd_front(t_stack **lst, t_stack *new);

// push_swap utils
int					ft_atoi(const char *nptr);
char				**ft_split(char const *s, char c);

// check
int	are_all_higher(t_stack *stack_a, t_stack *stack_b);

#endif