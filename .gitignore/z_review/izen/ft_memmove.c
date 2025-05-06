/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:57:50 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/06 18:33:39 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// コピー元とコピー先が重なっててもちゃんと作動するmemcpy
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_str;
	char	*src_str;
	size_t	i;

	i = 0;
	dst_str = (char *)dst;
	src_str = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst_str < src_str)
		return (ft_memcpy(dst, src, len));
	else
	{
		i = len;
		while (i-- > 0)
			dst_str[i] = src_str[i];
		return (dst);
	}
}
