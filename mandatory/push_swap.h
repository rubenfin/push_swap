/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 15:07:58 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/13 14:22:55 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				flag;
	int				numbered;
	int				stack_index;
	bool			above_median;
	int				push_cost;
	bool			cheapest;

	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;

// instructions
void				sa(t_stack **stack_a, size_t print);
void				sb(t_stack **stack_b, size_t print);
void				ss(t_stack **stack_a, t_stack **stack_b, size_t print);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a, size_t print);
void				rb(t_stack **stack_b, size_t print);
void				rr(t_stack **stack_a, t_stack **stack_b, size_t print);
void				rra(t_stack **stack_a, size_t print);
void				rrb(t_stack **stack_b, size_t print);
void				rrr(t_stack **stack_a, t_stack **stack_b, size_t print);

t_stack				*find_highest(t_stack *stack);
t_stack				*find_lowest(t_stack *stack);

// get target and handle cheapest
void				set_push_cost(t_stack *stack_a, t_stack *stack_b);
void				find_cheapest(t_stack **stack_a);
void				push_cheapest(t_stack **stack_a, t_stack **stack_b);
int					get_diverse(t_stack *stack_a, int a_length, int b_length);
void				find_target(t_stack *stack_a, t_stack *stack_b);

// stacks
void				sort_stack_of_5(t_stack **stack_a, t_stack **stack_b);
void				sort_stack_of_3(t_stack **stack_a);

// update
void				update_a_b_index(t_stack **a, t_stack **b);

// handle input
char				**convert_input(int argc, char *argv[]);
void				index_median_curr_stack(t_stack **stack);
void				get_numbered(t_stack **stack_a);
void				input_and_make_stack(int argc, char *argv[],
						t_stack **stack_a);
t_stack				*find_lowest(t_stack *stack);
void				push_lowest(t_stack **stack_a, t_stack **stack_b);
void				put_back(t_stack **stack_a, t_stack **stack_b);

// input_utils
int					ft_isnum(char c);
int					ft_strlen(char *str);
int					check_doubles(char **values);
int					check_integers(char **values);
long				*make_and_fill_int_arr(char **values);
int					fill_stack_a(char **values, t_stack **stack_a, int i);
// push_swap utils
long				ft_atoi(const char *nptr);
char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
int					stack_length(t_stack *stack_a);
void				go_to_last(t_stack **list);
int					get_last_value(t_stack *temp);
int					count_delimiter(char const *s, char c);
int					find_max(int a, int b);
void				put_lowest_first(t_stack **stack_a);
void				put_highest_first(t_stack **stack);

// check
int					are_all_higher(t_stack *stack_a, t_stack *stack_b);
int					check_sorted(t_stack *stack_a);

// clean
void				free_stack(t_stack **stack_a);
void				free_stacks(t_stack **stack_a, t_stack **stack_b);
void				free_values(char **values, int x);
void				print_err_exit(void);
void				free_values_matrix_exit(char **values, long *matrix);
// print
void				print_stack(t_stack *stack_a);
void				print_stack_index(t_stack *stack_a);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);
void				print_stacks_index(t_stack *stack_a, t_stack *stack_b);
void				print_stack_numbered(t_stack *stack_a);
void				print_all(t_stack *head);

#endif