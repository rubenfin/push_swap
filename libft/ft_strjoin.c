/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 17:24:06 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/02 11:58:48 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*full_s;
	int		i;

	full_s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!full_s)
		return (NULL);
	i = 0;
	while (*s1)
		full_s[i++] = *(s1++);
	while (*s2)
		full_s[i++] = *(s2++);
	full_s[i] = '\0';
	return (full_s);
}

// int main(void)
// {
//     const char str1[] = "HELLO    rdtgrdfxcv xc";
//     const char str2[] = "World  v";
//     char *full_string = ft_strjoin(str1, str2);
//     printf("%s\n", full_string);
//     free(full_string);
//     // printf("%s", full_string);
//     return (0);
// }