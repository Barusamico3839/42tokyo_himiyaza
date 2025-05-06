/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:31:20 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/28 23:29:56 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	byte;

	ptr = (unsigned char *)s;
	byte = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == byte)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
