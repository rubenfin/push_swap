/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:16:01 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/24 10:46:49 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen(dst);
	if (size == 0 || size <= dst_len)
	{
		return (src_len + size);
	}
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int main(void)
// {
//   char dst[30]; memset(dst, 0, 30);
// 	char * str = (char *)"AAAAAAAAA";

// char dst1[30]; memset(dst1, 0, 30);
// 	char * str1 = (char *)"AAAAAAAAA";

//     size_t size = ft_strlcat(dst, str, 5);
//     printf("ft: %s\n", dst);
//     printf("ft: %zu\n", size);

// 	size_t size1 = strlcat(dst1, str1, 5);
//     printf("strlcat: %s\n", dst1);
//     printf("strlcat: %zu\n", size1);
//     return (0);
// }