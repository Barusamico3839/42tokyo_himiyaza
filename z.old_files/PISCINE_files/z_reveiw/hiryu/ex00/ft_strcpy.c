/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 08:51:48 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 21:26:42 by himiyaza         ###   ########.fr       */
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
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	moto[] = "PISCINE";
	char	saki[50];

	printf("copy of moto: %s\n", moto);
	printf("copy return (value: %s\n", ft_strcpy(saki, moto));
	printf("copy of saki: %s\n", saki);
	return (0);
}
// strcpy copies string from a to b
// ft_strcpy copies string from a to c
