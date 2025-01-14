/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:54:31 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/02 09:42:50 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (0);
}

// int main(void)
// {
//     const char s[] = "Hel0l Wrld!";
//     char c = 'o';

//     printf("%s", ft_strrchr(s, c));
//     return (0);
// }