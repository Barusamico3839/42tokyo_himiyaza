/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:44:42 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 23:29:24 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= ' ' && str[i] <= '~'))
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

// 	str1 = "Hello!";
// 	str2 = "HELLO";
// 	str3 = "";
// 	str4 = "WORLDHello";
// 	printf("str1: %d\n", ft_str_is_printable(str1));
// 	printf("str2: %d\n", ft_str_is_printable(str2));
// 	printf("str3: %d\n", ft_str_is_printable(str3));
// 	printf("str4: %d\n", ft_str_is_printable(str4));
// 	return (0);
// }
