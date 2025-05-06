/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:34:52 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 01:56:13 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
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

// 	str1 = "Hello";      // 0
// 	str2 = "hello";      // 0
// 	str3 = "";           // 0
// 	str4 = "hellHello!"; // 0
// 	printf("str1: %d\n", ft_str_is_lowercase(str1));
// 	printf("str2: %d\n", ft_str_is_lowercase(str2));
// 	printf("str3: %d\n", ft_str_is_lowercase(str3));
// 	printf("str4: %d\n", ft_str_is_lowercase(str4));
// 	return (0);
// }
