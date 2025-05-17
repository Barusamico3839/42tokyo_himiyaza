/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:36:04 by jferro            #+#    #+#             */
/*   Updated: 2025/04/02 03:37:08 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;

	len = 0;
	while (src[len] != 0)
		len++;
	dest = (char *)malloc((len + 1) * 1);
	if (dest == 0)
		return (0);
	len = 0;
	while (src[len] != 0)
	{
		dest[len] = src[len];
		len++;
	}
	return (dest);
}
#include <stdio.h>

int	main(void)
{
	char	*src;

	src = "hello";
	printf("scr;%s\n", src);
	printf("dest;%s\n", ft_strdup(src));
	return (0);
}
