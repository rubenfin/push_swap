/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:35:01 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/31 17:27:11 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *) &ptr[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s[] = "this is at est et";
// 	char	*string;
// 	char	*string2;

// 	// char c = 0;
// 	string = ft_memchr(s, 'e', 12);
// 	string2 = memchr(s, 'e', 12);
// 	printf("ft: %s\n", string);
// 	printf("memchr: %s\n", string2);
// 	return (0);
// }
