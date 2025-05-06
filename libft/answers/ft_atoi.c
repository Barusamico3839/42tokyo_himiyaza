/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:07:01 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/27 11:21:41 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// int main(void)
// {
// 	char str1[] = "   -1234";
// 	char str2[] = "   +1234";
// 	char str3[] = "   1234";
// 	char str4[] = "   -0";
// 	char str5[] = "   +0";
// 	char str6[] = "   0";
// 	char str7[] = "   -2147483648";
// 	char str8[] = "   2147483647";
// 	char str9[] = "   -2147483649";
// 	char str10[] = "   2147483648";
// 	char str11[] = "   -1234abc";
// 	char str12[] = "   +1234abc";
// 	char str13[] = "   1234abc";
// 	char str14[] = "   -abc1234";
// 	char str15[] = "   +abc1234";
// 	char str16[] = "   abc1234";
// 	char str17[] = "   -1234.5678";
// 	char str18[] = "   +1234.5678";
// 	char str19[] = "   1234.5678";
// 	char str20[] = "   -0.0";
// 	char str21[] = "   +0.0";
// 	char str22[] = "   0.0";
// 	char str23[] = "   -1234.0";
// 	char str24[] = "   +1234.0";
// 	char str25[] = "   1234.0";
// 	char str26[] = "   -0.1234";
// 	char str27[] = "   +0.1234";
// 	char str28[] = "   0.1234";
// 	char str29[] = "   -1234.5678abc";
// 	char str30[] = "   +1234.5678abc";
// 	char str31[] = "   1234.5678abc";
// 	char str32[] = "   -abc1234.5678";
// 	char str33[] = "   +abc1234.5678";
// 	char str34[] = "   abc1234.5678";
// 	char str35[] = "   -1234.5678abc";
// 	char str36[] = "   +1234.5678abc";

/
