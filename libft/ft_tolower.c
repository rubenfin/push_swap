/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:38:37 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/10 16:19:20 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}

// int main(void)
// {
//     char c;

//     c = 'm';
//     printf("%c -> %c", c, ft_tolower(c));

//     c = 'D';
//     printf("\n%c -> %c", c, ft_tolower(c));

//     c = '9';
//     printf("\n%c -> %c", c, tolower(c));
//     return (0);
// }