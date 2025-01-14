/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 12:02:45 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/10/30 13:55:59 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign_count(char num)
{
	int	sign;

	sign = 1;
	if (num == '-')
	{
		sign = -1;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int		value;
	int		sign;
	char	*num;
	int		i;

	i = 0;
	value = 0;
	sign = 1;
	num = (char *)nptr;
	while (num[i] == ' ' || (num[i] >= 9 && num[i] <= 13))
	{
		i++;
	}
	if (num[i] == '-' || num[i] == '+')
	{
		sign = sign_count(num[i]);
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		value = value * 10 + (num[i] - '0');
		i++;
	}
	return (value * sign);
}

// int	main(void)
// {
// 	const char	str[] =  "  -235rer643 -2342";
// 	const char	str2[] = "  -235rer643 -2342";
// 	int			num;
// 	int			num2;

// 	num = ft_atoi(str);
// 	num2 = atoi(str2);
// 	printf("ft_atoi: %d\n", num);
// 	printf("atoi   : %d\n", num2);
// 	return (0);
// }

// ft_atoi         : 1.KO  5.KO 6.KO 8.KO 9.KO 10.KO 11.KO
// int main(void)
// {
// 	signal(SIGSEGV, sigsegv);
// 	title("ft_atoi\t\t: ")

// 	char escape[] = {9, 10, 11, 12, 13, 0};
// 	string e(escape);
// 	/* 1 */ check(ft_atoi((e + "1").c_str()) == 1); showLeaks();
// 	/* 2 */ check(ft_atoi((e + "a1").c_str()) == 0); showLeaks();
// 	/* 3 */ check(ft_atoi((e + "--1").c_str()) == 0); showLeaks();
// 	/* 4 */ check(ft_atoi((e + "++1").c_str()) == 0); showLeaks();
// 	/* 5 */ check(ft_atoi((e + "+1").c_str()) == 1); showLeaks();
// 	/* 6 */ check(ft_atoi((e + "-1").c_str()) == -1); showLeaks();
// 	/* 7 */ check(ft_atoi((e + "0").c_str()) == 0); showLeaks();
// 	/* 8 */ check(ft_atoi((e + "+42lyon").c_str()) == 42); showLeaks();
// 	/* 9 */ check(ft_atoi((e + "+101").c_str()) == 101); showLeaks();
// 	/* 10 */ check(ft_atoi((e
// + to_string(INT_MAX)).c_str()) == INT_MAX); showLeaks();
// 	/* 11 */ check(ft_atoi((e
// + to_string(INT_MIN)).c_str()) == INT_MIN); showLeaks();
// 	/* 12 */ check(ft_atoi("-+42") == 0); showLeaks();
// 	/* 13 */ check(ft_atoi("+-42") == 0); showLeaks();
// 	/* 14 */ check(ft_atoi((string("+") + e + "42").c_str()) == 0); showLeaks();
// 	/* 15 */ check(ft_atoi((string("-") + e + "42").c_str()) == 0); showLeaks();
// 	/* 16 */ check(ft_atoi((string("1") + e + "42").c_str()) == 1); showLeaks();
// 	/* 17 */ check(ft_atoi((string("-1") + e + "42").c_str()) ==
// 		-1); showLeaks();
// // 	write(1, "\n", 1);
// 	return (0);
// }