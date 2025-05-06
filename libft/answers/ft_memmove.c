/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:32:10 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/27 13:32:17 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)dst;
	str2 = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (str1 < str2)
	{
		i = 0;
		while (i < len)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			str1[i - 1] = str2[i - 1];
			i--;
		}
	}
	return (dst);
}

