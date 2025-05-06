/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:02:28 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 21:29:57 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello!";
	char	str2[] = "hello";
	char	str3[] = "";
	char	str4[] = "helloHello!";

	printf("str1: %s\n", ft_strupcase(str1));
	printf("str2: %s\n", ft_strupcase(str2));
	printf("str3: %s\n", ft_strupcase(str3));
	printf("str4: %s\n", ft_strupcase(str4));
	return (0);
}
