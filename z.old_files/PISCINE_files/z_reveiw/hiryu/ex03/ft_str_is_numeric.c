/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:30:31 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 21:29:18 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
#include <stdio.h>

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "Hello";   // 0
	str2 = "42";      // 1
	str3 = "";        // 1
	str4 = "42Hello"; // 0
	printf("str1: %d\n", ft_str_is_numeric(str1));
	printf("str2: %d\n", ft_str_is_numeric(str2));
	printf("str3: %d\n", ft_str_is_numeric(str3));
	printf("str4: %d\n", ft_str_is_numeric(str4));
	return (0);
}
