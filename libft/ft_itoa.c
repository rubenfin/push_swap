/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:38:46 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/16 15:05:14 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_string(char *str, int sign)
{
	int		length;
	int		i;
	int		j;
	char	temp;

	i = 0;
	length = ft_strlen(str);
	j = length - 1;
	if (sign == -1)
	{
		str[i] = '-';
		i++;
	}
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	get_sign(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (1);
}

char	*ft_itoa(int n)
{
	int				sign;
	int				num_digits;
	char			*ascii;
	int				i;
	unsigned int	num;

	sign = get_sign(n);
	num = n * sign;
	if (n == 0)
		return (ft_strdup("0"));
	num_digits = count_digits(num);
	ascii = (char *)malloc(num_digits + (sign == -1) + 1);
	if (ascii == NULL)
		return (NULL);
	i = 0;
	if (sign == -1)
		ascii[i++] = '-';
	while (num > 0)
	{
		ascii[i++] = '0' + (num % 10);
		num /= 10;
	}
	ascii[i] = '\0';
	reverse_string(ascii, sign);
	return (ascii);
}

// int	main(void)
// {
// 	int n = -2147483648;
// 	char *num = ft_itoa(n);
// 	printf("%s", num);
// 	return (0);
// }