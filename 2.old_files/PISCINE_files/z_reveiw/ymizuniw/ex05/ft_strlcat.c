/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:23:09 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/24 18:43:48 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	i;

	dest_length = 0;
	src_length = 0;
	i = 0;
	while (dest[dest_length] != 0)
		dest_length++;
	while (src[src_length] != 0)
		src_length++;
	if (size <= dest_length)
		return (src_length + size);
	while (i < src_length && i < size - 1 - dest_length)
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest_length + src_length);
}

#include <stdio.h>

int	main(void)
{
	char	dest[20] = "abcdef";
	char	src[] = "abcd";

	printf("%d\n", ft_strlcat(dest, src, 13));
	printf("%s\n", dest);
	return (0);
}
