/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:07:39 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/06 19:06:31 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// string length concatenate. dstsize - dst 分,srcを連結させる。
// dstsize - dst < 0のときは連結は行わない。
// 加えて戻り値は,dstsizeがそもそもdstの文字列より小さく、連結できないときは、
// (dstsize)ではなくsrc_len + dstsizeを返す
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = dst_len;
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
#include <stdio.h>

int	main(void)
{
	char	dst[10];
	char	*src;

	src = "hello";
	ft_strlcat(dst, src, 14);
	printf("%s", dst);
	return (0);
}
