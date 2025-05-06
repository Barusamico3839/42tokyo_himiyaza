/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:45:44 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 16:56:42 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'z' || (str[i] > 'Z' && str[i] < 'a'))
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

	str1 = "Hello, World!"; // 0
	str2 = "HelloWorld";    // 1
	str3 =                  // 1
		str4 = "";          // 1
	printf("str1: %d\n", ft_str_is_alpha(str1));
	printf("str2: %d\n", ft_str_is_alpha(str2));
	printf("str3: %d\n", ft_str_is_alpha(str3));
	printf("str4: %d\n", ft_str_is_alpha(str4));
	return (0);
}
