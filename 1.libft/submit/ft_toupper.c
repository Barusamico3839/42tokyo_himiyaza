/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:33:30 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:28:09 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = "hello World";
// 	while (str[i] != 0)
// 	{
// 		printf("%c", ft_toupper(str[i]));
// 		i++;
// 	}
// 	return (0);
// }
