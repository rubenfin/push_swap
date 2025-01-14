/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 08:51:36 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/02 12:06:40 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	int		len;
	char	*start;
	char	*end;

	len = ft_strlen((char *)s1);
	start = (char *)s1;
	end = (char *)s1 + len - 1;
	while (start && checker(*start, set))
		start++;
	while (end > start && checker(*end, set))
		end--;
	new_s = (char *)malloc((end - start) + 2);
	if (!new_s)
		return (NULL);
	new_s = ft_memmove(new_s, start, (end - start + 1));
	new_s[end - start + 1] = '\0';
	return (new_s);
}

// int	main(void)
// {
// 	char const	str[] = "";
// 	char const	trim[] = "123";
// 	char		*new_s;

// 	new_s = ft_strtrim(str, trim);
// 	printf("%s ", new_s);
// 	return (0);
// }
