/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:03:43 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 17:06:46 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	j = i;
	while (j < size)
	{
		dest[j] = '\0';
		j++;
	}
	return (i);
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	moto[] = "He";
	char	saki[20];
	int		size;

	size = 5;
	printf("copy moto................%s\n", moto);
	printf("before copying to saki...%s\n", saki);
	printf("return (value (moto size)%i\n", ft_strlcpy(saki, moto, size));
	printf("after copying to saki....%s\n", saki);
	return (0);
}
