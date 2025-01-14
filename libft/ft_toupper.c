/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:32:28 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/10 16:19:24 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}

// int main(void)
// {   char c;

//     c = 'a';
//     printf("%c -> %c\n", c, toupper(c));
//     printf("%c -> %c", c, ft_toupper(c));

//     c = 'Z';
//     printf("\n%c -> %c", c, toupper(c));
//     printf("\n%c -> %c", c, ft_toupper(c));

//     c = '9';
//     printf("\n%c -> %c", c, toupper(c));
//     printf("\n%c -> %c", c, ft_toupper(c));

//     return (0);
// }