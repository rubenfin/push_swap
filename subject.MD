# push_swap instructions

sa (swap a): Swap 2 first elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b): Swap 2 first elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time

pa (push a): Take the first element at the the top of b and put it at the top of a. Do nothing if b is empty
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time 

allowed functions: read, write, malloc, free, exit, ft_printf

//


void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*curr;
	t_stack	*temp;
	int		lowest;
	int		length;
	int		found;

	length = 0;
	found = 0;
	stack_b = NULL;
	lowest = INT_MAX;
	curr = *stack_a;
	temp = *stack_a;
	while (curr)
	{
		if (lowest > curr->value)
			lowest = curr->value;
		curr = curr->next;
		length++;
	}
	while (temp->value != lowest)
	{
		temp = temp->next;
		found++;
	}
	if (found <= length / 2)
	{
		while ((*stack_a)->value != lowest)
		{
			ra(stack_a);
		}
		return ;
	}
	if (found > length / 2)
	{
		while ((*stack_a)->value != lowest)
		{
			rra(stack_a);
		}
	}
}

int	list_counter(t_stack *stack_a)
{
	t_stack	*temp;
	int		length;

	temp = stack_a;
	length = 0;
	while (temp->next)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}

void	move_half(t_stack **stack_a, t_stack **stack_b, double median,
		int length)
{
	t_stack	*temp;
	int		i;

	temp = *stack_a;
	printf("LENGTH : %d , LENGTH  / 2: %d LENGTH.2: %d\n", length, length / 2,
		length % 2);
	i = 0;
	if (length % 2 == 1)
		i = 1;
	while (list_counter(*stack_a) >= ((length / 2) + (length % 2) - i))
	{
		if ((*stack_a)->value < median)
		{
			pb(stack_a, stack_b);
		}
		ra(stack_a);
	}
}

int	lowest_num_check(t_stack *stack_a)
{
	t_stack	*curr;
	int		lowest;

	lowest = INT_MAX;
	curr = stack_a;
	while (curr)
	{
		if (lowest > curr->value)
			lowest = curr->value;
		curr = curr->next;
	}
	return (lowest);
}

int	check_ascending(t_stack *stack_a)
{
	int		checker;
	t_stack	*temp;

	temp = stack_a;
	checker = lowest_num_check(stack_a);
	printf("checker %d\n", checker);
	while (temp)
	{
		if (temp->value > checker)
			checker = temp->value;
		else
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_both_stacks(t_stack **stack_a, t_stack **stack_b)
{
	stack_b = NULL;
	while (!check_ascending(*stack_a))
	{
		print_stack(*stack_a);
		if ((*stack_a)->value < (*stack_a)->next->value)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
		{
			ra(stack_a);
		}
		if (check_ascending(*stack_a))
			return ;
	}
}
void	sort_double_arr(double **array, int length)
{
	double	temp;

	int i, j;
	for (i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if ((*array)[i] > (*array)[j])
			{
				temp = (*array)[i];
				(*array)[i] = (*array)[j];
				(*array)[j] = temp;
			}
		}
	}
}

double	get_median(t_stack *stack_a)
{
	t_stack	*temp;
	double	*array;
	double	median;

	int length, i;
	length = list_counter(stack_a);
	i = 0;
	temp = stack_a;
	array = malloc(1024 * sizeof(double));
	while (temp)
	{
		array[i] = (double)temp->value;
		temp = temp->next;
		i++;
	}
	sort_double_arr(&array, length);
	if (length % 2 == 0)
	{
		median = array[length / 2];
	}
	else
	{
		median = (array[length / 2] + array[(length / 2) + 1]) / 2.0;
	}
	return (median);
}