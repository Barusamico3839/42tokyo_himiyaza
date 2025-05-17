/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:03:43 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 22:58:30 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	moto[] = "Hello hello";
// 	char	saki[20];
// 	int		size;

// 	size = 5;
// 	printf("copy moto................%s\n", moto);
// 	printf("before copying to saki...%s\n", saki);
// 	printf("return (value (moto size)%i\n", ft_strlcpy(saki, moto, size));
// 	printf("after copying to saki....%s\n", saki);
// 	return (0);
// }
