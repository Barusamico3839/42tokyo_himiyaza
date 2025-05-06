/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:36:21 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:42 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	src[] = "Hello, World!";
// 	char	dest[20];
// 	char	dest2[20];

// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);
// 	printf("dest2: %s\n", dest2);
// 	printf("strcpy: %s\n", strcpy(dest, src));
// 	printf("ft_strcpy: %s\n", ft_strcpy(dest2, src));
// 	return (0);
// }
