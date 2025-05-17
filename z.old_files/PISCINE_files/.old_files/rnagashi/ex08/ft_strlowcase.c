/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:27:31 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 17:05:20 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello!";
	char	str2[] = "HELLO";
	char	str3[] = "";
	char	str4[] = "HELLOHello";

	printf("str1: %s\n", ft_strlowcase(str1));
	printf("str2: %s\n", ft_strlowcase(str2));
	printf("str3: %s\n", ft_strlowcase(str3));
	printf("str4: %s\n", ft_strlowcase(str4));
	return (0);
}
