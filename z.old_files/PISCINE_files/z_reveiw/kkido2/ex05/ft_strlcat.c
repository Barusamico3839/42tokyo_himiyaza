/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:32:51 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/26 17:56:20 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	i;

	dest_length = 0;
	src_length = 0;
	i = 0;
	while (dest[dest_length] != '\0')
		dest_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (size <= dest_length)
		return (size + src_length);
	while (src[i] != '\0' && dest_length + i < size - 1)
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	if (dest_length + i < size)
		dest[dest_length + i] = '\0';
	return (dest_length + src_length);
}

#include <stdio.h>

int	main(void)
{
	char			*src;
	unsigned int	size;
	char			dest[] = "Hello";

	src = "1234567890";
	size = 20;
	printf("%i\n", ft_strlcat(dest, src, size));
	printf("%s", dest);
}
