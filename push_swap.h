/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 15:07:58 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/05 16:33:06 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				value;
	int				flag;
	struct s_stack	*next;
}					t_stack;

// instructions
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// handle input
char				**convert_input(int argc, char *argv[]);

// push_swap utils
long long			ft_atoi(const char *nptr);
char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_itoa(int n);

// check
int					are_all_higher(t_stack *stack_a, t_stack *stack_b);

// print 
void	print_stack(t_stack *stack_a);
void	print_stack_index(t_stack *stack_a);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	print_stacks_index(t_stack *stack_a, t_stack *stack_b);

#endif