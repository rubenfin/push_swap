/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 12:54:43 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/16 11:19:33 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-', fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9)
	{
		ft_putchar(n + '0', fd);
	}
}

// int main(void)
// {
//     int fileDescriptor = open("putnbr_fd.txt", O_WRONLY | O_TRUNC | O_CREAT,
// 		0640);
//     int n = -123;

//     if (fileDescriptor != 1)
//     {
//         printf("fd successfully opened\n");

//         ft_putnbr_fd(n, fileDescriptor);

//         int close_value = close(fileDescriptor);

//         if (close_value != 1)
//         {
//             printf("fd successfully closed\n");
//         }
//     }
//     return (0);
// }