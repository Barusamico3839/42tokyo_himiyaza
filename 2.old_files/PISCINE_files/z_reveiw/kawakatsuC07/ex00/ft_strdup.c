/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:36:04 by jferro            #+#    #+#             */
/*   Updated: 2025/04/02 06:39:18 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	len = i;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	*src;

// 	src = "hello";
// 	printf("scr;%s\n", src);
// 	printf("dest;%s\n", ft_strdup(src));
// 	return (0);
// }
