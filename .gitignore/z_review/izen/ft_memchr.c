/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:18:55 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:26:44 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// メモリ領域*s内でｃを見つけて、そこのポインタを返す。ｎバイトまで検索する。
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
