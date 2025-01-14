/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 13:44:23 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/31 17:22:59 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)array)[i] = '\0';
		i++;
	}
	return (array);
}

// int main(void)
// {
//     size_t nmemb = SIZE_MAX;
//     size_t size = SIZE_MAX;
//     void *ptr = ft_calloc(nmemb, sizeof(int));
//     printf("%p\n", ptr);
//     free(ptr);
//     return (0);
// }