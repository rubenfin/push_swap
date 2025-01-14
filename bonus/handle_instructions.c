/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_instructions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 09:28:10 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 10:35:17 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_instruction(char *total_instructions)
{
	char	*single_instruction;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (total_instructions[i] && total_instructions[i] != '\n')
		i++;
	if (total_instructions[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	single_instruction = (char *)malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		single_instruction[j] = total_instructions[j];
		j++;
	}
	single_instruction[j] = '\0';
	return (single_instruction);
}

char	*remove_instruction(char *total_instructions)
{
	char	*new_instruction;
	int		length;
	int		i;

	i = 0;
	length = 0;
	if (!total_instructions[0])
		return (free(total_instructions), NULL);
	while (total_instructions[length] && total_instructions[length] != '\n')
		length++;
	if (total_instructions[length] == '\n')
		length++;
	new_instruction = (char *)malloc(((ft_strlen(total_instructions) - length)
				+ 1) * sizeof(char));
	while (total_instructions[length])
	{
		new_instruction[i] = total_instructions[length];
		i++;
		length++;
	}
	new_instruction[i] = '\0';
	free(total_instructions);
	return (new_instruction);
}

char	*make_instruction(char **total_instructions)
{
	char	*instruction;

	instruction = get_instruction(*total_instructions);
	*total_instructions = remove_instruction(*total_instructions);
	return (instruction);
}

char	*get_all_instruction(void)
{
	char	*buffer;
	char	*total_instructions;

	total_instructions = malloc(1);
	if (!total_instructions)
		return (0);
	total_instructions[0] = '\0';
	while (1)
	{
		buffer = get_next_line(STDIN_FILENO);
		if (!buffer)
			break ;
		total_instructions = ft_strjoin_gnl(total_instructions, buffer);
		if (!total_instructions)
			return (free(buffer), NULL);
		free(buffer);
		buffer = NULL;
	}
	return (total_instructions);
}

int	read_instructions(t_stack **a, t_stack **b)
{
	char	*total_instructions;
	char	*instruction;

	total_instructions = get_all_instruction();
	if (!total_instructions)
		return (1);
	while (1)
	{
		instruction = make_instruction(&total_instructions);
		if (!instruction)
			break ;
		do_instruction(a, b, &instruction, &total_instructions);
		free(instruction);
		instruction = NULL;
	}
	return (1);
}
