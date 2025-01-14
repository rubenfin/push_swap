/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 11:33:28 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/31 15:54:18 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*src_p;
	char		*dest_p;

	if (!dest && !src)
		return (NULL);
	i = 0;
	src_p = (const char *)src;
	dest_p = (char *)dest;
	while (i < n)
	{
		dest_p[i] = src_p[i];
		i++;
	}
	return (dest_p);
}

// int main(void)
// {
//     char *src = "Hello World";
//     char dest[300];

//     printf("%s", ft_memcpy(dest, src, 90));
//     return (0);
// }
