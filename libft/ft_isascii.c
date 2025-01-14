/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:42:21 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/10 15:42:23 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int main(void)
// {
//     printf("%d\n", ft_isascii(-1));
//     printf("%d\n", isascii(-1));
//     return (0);
// }