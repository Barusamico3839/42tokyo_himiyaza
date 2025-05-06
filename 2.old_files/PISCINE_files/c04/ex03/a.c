/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:10:43 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/24 10:15:22 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (n * sign);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "  -42";
// 	printf("%d\n", ft_atoi(str));
// 	return (0);
// }
