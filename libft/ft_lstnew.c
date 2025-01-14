/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 14:56:54 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/21 11:27:56 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*member;

	member = (t_list *)malloc(sizeof(t_list));
	if (!member)
		return (NULL);
	member->content = content;
	member->next = NULL;
	return (member);
}

// int	main(void)
// {
// 	int		data;
// 	t_list	*new_node;

// 	data = 42;
// 	new_node = ft_lstnew(&data);
// 	if (new_node)
// 	{
// 		printf("%p - pointer content\n", new_node->content);
// 		printf("%p - pointer next\n", new_node->next);
// 		free(new_node);
// 	}
// 	return (0);
// }
