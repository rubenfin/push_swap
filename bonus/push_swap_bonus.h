/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 14:43:05 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 10:37:42 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "gnl/get_next_line.h"
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

	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **stack_a, size_t print);
void				sb(t_stack **stack_b, size_t print);
void				ss(t_stack **stack_a, t_stack **stack_b, size_t print);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stauck_a, t_stack **stack_b);
void				ra(t_stack **stack_a, size_t print);
void				rb(t_stack **stack_b, size_t print);
void				rr(t_stack **stack_a, t_stack **stack_b, size_t print);
void				rra(t_stack **stack_a, size_t print);
void				rrb(t_stack **stack_b, size_t print);
void				rrr(t_stack **stack_a, t_stack **stack_b, size_t print);

// handle instructions
char				*get_instruction(char *total_instructions);
char				*remove_instruction(char *total_instructions);
char				*make_instruction(char **total_instructions);
char				*get_all_instruction(void);
int					read_instructions(t_stack **a, t_stack **b);
void				do_instruction(t_stack **a, t_stack **b, char **instruction,
						char **total_instructions);

int					stack_len(t_stack *stack);
int					ft_strcmp(char *s1, char *s2);
int					ft_isnum(char c);

// check_input
int					check_doubles(char **values);
int					check_integers(char **values);
void				check_all(char **values, int argc);
int					argv_check(int argc, char *argv[]);
void				check_all(char **values, int argc);

// handle input
char				**move_argv_to_values(int argc, char *argv[]);
char				**convert_input(int argc, char *argv[]);
int					fill_stack_a(char **values, t_stack **stack_a, int i);
void				input_and_make_stack(int argc, char *argv[],
						t_stack **stack_a);
long				*make_and_fill_int_arr(char **values);
int					ft_isnum(char c);
int					check_doubles(char **values);
int					check_integers(char **values);

void				free_stack(t_stack **stack_a);
void				free_stacks(t_stack **stack_a, t_stack **stack_b);
void				free_values(char **values, int x);
void				print_err_exit(void);
void				free_values_matrix_exit(char **values, long *matrix);

long				ft_atoi_bonus(const char *nptr);
char				**ft_split(char const *s, char c);

#endif