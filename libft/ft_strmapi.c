/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 17:17:34 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/02 11:59:45 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	lowercase(unsigned int i, char c)
// {
// 	if (c >= 'A' && c <= 'Z')
// 	{
// 		c = c + 32;
// 	}
// 	return (c);
// }

// static char	uppercase(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 	{
// 		if (c >= 'a' && c <= 'z')
// 		{
// 			c = c - 32;
// 		}
// 	}
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		length;
	char	*mystring;
	int		i;

	length = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	mystring = (char *)malloc(length + 1);
	if (!mystring)
		return (NULL);
	i = 0;
	while (i < length)
	{
		mystring[i] = f(i, s[i]);
		i++;
	}
	mystring[i] = '\0';
	return (mystring);
}

// int	main(void)
// {
// 	char *upper = ft_strmapi("this", uppercase);
// 	printf("%s\n", upper);
// 	free(upper);
// 	// char *lower = ft_strmapi("hello world", lowercase);
// 	// printf("%s\n", lower);
// 	return (0);
// }