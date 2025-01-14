/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 09:52:24 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/31 15:47:04 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	uppercase(unsigned int i, char *c)
// {
// 	if (c[i] >= 'a' && c[i] <= 'z')
// 	{
// 		c[i] = c[i] - 32;
// 	}
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int main(void)
// {
//     char sentence[] = "hello world";
//     ft_striteri(sentence, uppercase);
//     printf("%s", sentence);
//     return (0);
// }