/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 12:45:51 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/10 16:16:22 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

// int main(void)
// {
//     int fileDescriptor = open("putendl.txt", O_WRONLY | O_TRUNC | O_CREAT,
		// 0640);
//     char *s = "this is a sentence";

//     if (fileDescriptor != -1)
//     {
//         printf("fd successfully opened\n");
//         ft_putendl_fd(s, fileDescriptor);
//     }
//     int close_value = close(fileDescriptor);

//     if (close_value != -1)
//     {
//         printf("fd successfully closed\n");
//     }

//     return (0);
// }