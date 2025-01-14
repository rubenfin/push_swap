/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 11:57:53 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/24 11:11:38 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_p;
	const char	*src_p;

	if (!dest && !src)
		return (NULL);
	src_p = (const char *)src;
	dest_p = (char *)dest;
	if (dest_p > src_p && dest_p < src_p + n)
	{
		dest_p += n - 1;
		src_p += n - 1;
		while (n--)
		{
			*dest_p-- = *src_p--;
		}
	}
	else
	{
		while (n--)
		{
			*dest_p++ = *src_p++;
		}
	}
	return (dest);
}

// int main(void)
// {
//     char src[] = "memmove can be very useful......";
//     char src2[] = "memmove can be very useful......";
//     // char dest[14];
//     ft_memmove(src + 15, src + 10, 20);
//     memmove(src2 + 15, src2 + 10, 20);
//     printf("%s\n", src);
//     printf("%s\n", src2);
//     return (0);
// }
