/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 16:43:00 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/24 11:10:35 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// int main(void)
// {

//     printf("%d\n", ft_isalpha('c') );
//     printf("%d", isalpha('c'));
//     return (0);
// }