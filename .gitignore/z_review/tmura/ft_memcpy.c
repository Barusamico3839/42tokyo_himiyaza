/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:27:13 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:26:53 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// srcのメモリ領域からdestのメモリ領域にｎバイト分コピーする。
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_str;
	char	*src_str;
	size_t	i;

	i = 0;
	dst_str = (char *)dst;
	src_str = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	return (dst);
}
