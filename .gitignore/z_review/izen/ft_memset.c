/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:28:28 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/06 18:23:39 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uc;

	i = 0;
	str = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i < len)
	{
		str[i] = uc;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[5] = "12345";

// 	printf("%s\n", str);
// 	ft_memset(str, '0', 3);
// 	printf("%s\n", str);
// 	return (0);
// }
