/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:48:01 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/11/02 12:11:54 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	char			*substr;
	unsigned int	size;

	i = 0;
	j = 0;
	size = ft_strlen((char *)s);
	if (size == 0)
		return (ft_strdup(""));
	if (start >= size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[i])
	{
		if (i >= start && i - start < len)
			substr[j++] = s[i];
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

// int main(void)
// {
//     char const str[] = "tripouille";
//     unsigned int start = 1;
//     size_t length = 1;
//     char *substr = ft_substr(str, start, length);
//     printf("substr: %s\n", substr);
//     free(substr);
//     printf("free : %s\n", substr);
//     return (0);
// }