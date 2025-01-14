/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:44:09 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/12 13:26:19 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	s[] = "tripouille";
// 	const char	s2[] = "tripouille";
// 	int		c;
// 	char		*ptr;
// 	char		*ptr2;

// 	c = 'r';
// 	ptr = ft_strchr(s, c);
// 	ptr2 = strchr(s2, c);
// 	printf("ft: %s\n", ptr);
// 	printf("strchr: %s\n", ptr2);
// 	return (0);
// }