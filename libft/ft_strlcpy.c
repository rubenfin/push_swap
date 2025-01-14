/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:52:45 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/31 16:03:14 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (size > i)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char str[] = "coucou";
// 	char dst[10];
// 	ft_memset(dst, 'A', 10);
// 	size_t size = ft_strlcpy(dst, str, 2);
// 	printf("ft: %s\n", dst);
// 	printf("ft: %c\n", dst[1]);
// 	printf("ft: %c\n", dst[2]);
// 	printf("ft: %ld\n", size);
// 	return (0);
// }