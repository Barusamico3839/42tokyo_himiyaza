/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:57:52 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 16:55:47 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	moto[] = "Hello, World!";
	char	saki[20];
	int		size;

	size = 5;
	printf("copy moto................%s\n", moto);
	printf("before copying to saki...%s\n", saki);
	printf("return (value size(%i)...%s\n", size, ft_strncpy(saki, moto, size));
	printf("after copying to saki....%s\n", saki);
	return (0);
}
