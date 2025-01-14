/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 10:38:24 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/12 10:45:56 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
//     int fileDescriptor = open("putchar.txt", O_WRONLY | O_TRUNC | O_CREAT,
// 		0640);
//     char c = 'Z';

//     if (fileDescriptor != -1)
//     {
//         printf("filedescriptor 200\n");
//         ft_putchar_fd(c, fileDescriptor);

//         int closeresult = close(fileDescriptor);

//         if (closeresult == 0)
//         {
//             printf("file successfully closed!");
//         }
//     }

//     return (0);
// }
