/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:36:15 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 23:29:28 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;
// 	char	*str4;

// 	str1 = "Hello";       // 0
// 	str2 = "HELLO";       // 1
// 	str3 = "";            // 1
// 	str4 = "HELLOHello!"; // 0
// 	printf("str1: %d\n", ft_str_is_uppercase(str1));
// 	printf("str2: %d\n", ft_str_is_uppercase(str2));
// 	printf("str3: %d\n", ft_str_is_uppercase(str3));
// 	printf("str4: %d\n", ft_str_is_uppercase(str4));
// 	return (0);
// }
