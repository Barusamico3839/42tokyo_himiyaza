/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:10:02 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/24 10:14:56 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Hello, World!";
// 	ft_putstr(str);
// 	return (0);
// }
