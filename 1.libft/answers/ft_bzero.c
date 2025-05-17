/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:12:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/26 17:54:58 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

// int main(void)
// {
// 	char str[10] = "Hello";
// 	printf("Before ft_bzero: %s\n", str);
// 	ft_bzero(str, 5);
// 	printf("After ft_bzero: %s\n", str);
// 	return (0);
