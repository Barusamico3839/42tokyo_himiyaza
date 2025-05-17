/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:49:14 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:29:54 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa2(size_t int_len, long long_n2)
{
	char	*str;

	str = (char *)ft_calloc(int_len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (long_n2 == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (int_len > 0)
	{
		if (long_n2 == 0)
		{
			str[0] = '-';
			break ;
		}
		str[int_len - 1] = long_n2 % 10 + '0';
		long_n2 = long_n2 / 10;
		int_len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	long_n;
	long	long_n2;
	size_t	int_len;

	int_len = 1;
	long_n = n;
	if (long_n < 0)
	{
		long_n = -long_n;
		int_len++;
	}
	long_n2 = long_n;
	while (long_n > 9)
	{
		long_n = long_n / 10;
		int_len++;
	}
	return (itoa2(int_len, long_n2));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	n;

// 	n = -1234;
// 	printf("%s", ft_itoa(n));
// 	return (0);
// }
