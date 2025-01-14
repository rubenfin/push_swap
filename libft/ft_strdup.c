/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 15:57:01 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/02 11:58:02 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;
	char	*temp;

	i = 0;
	ptr = (char *)s;
	while (*s)
	{
		i++;
		s++;
	}
	temp = malloc((i + 1) * sizeof(char));
	if (!temp)
		return (0);
	while (*ptr)
	{
		*temp = *ptr;
		temp++;
		ptr++;
	}
	*temp = '\0';
	return (temp - i);
}

// int main(void)
// {
//     const char str[] = "string duplicate";
//     char *mystring = ft_strdup(str);
//     printf("%s\n", mystring);
//     free(mystring);
//     return (0);
// }