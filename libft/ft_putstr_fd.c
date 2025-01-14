/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 10:36:20 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/12 10:48:44 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main(void)
// {
//     int fileDescriptor = open("putstr.txt", O_WRONLY | O_TRUNC | O_CREAT,
//		0640);
//     char *s = "my sentence";

//     if (fileDescriptor != 1)
//     {
//         printf("succesfully opened fd\n");
//         ft_putstr_fd(s, fileDescriptor);
//         int close_value = close(fileDescriptor);
//         if (close_value != 1)
//         {
//             printf("succesfully closed fd\n");
//         }
//     }

//     return (0);
// }
