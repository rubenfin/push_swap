/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 18:06:54 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/10 15:45:33 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int arg)
{
	return (arg >= 32 && arg <= 126);
}

// int main(void)
// {
//     ft_isprint(11);
//     return (0);
// }