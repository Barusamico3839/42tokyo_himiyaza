/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:31:57 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/28 12:35:06 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// srcのメモリ領域からdestのメモリ領域にｎバイト分コピーする。
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)dst;
	str2 = (char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
