/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 10:00:57 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/16 16:51:23 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		x;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (*big && i < len)
	{
		x = 0;
		while (*big == *little && i < len)
		{
			x++;
			little++;
			big++;
			if (*little == '\0')
				return ((char *)big - x);
			i++;
		}
		i -= x;
		little -= x;
		big -= x;
		big++;
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char haystack[30] = "aaabcabcd";

//     char *str = ft_strnstr(haystack, "abcd", 9);
//     printf("ft: %s", str);
//     return (0);
// }