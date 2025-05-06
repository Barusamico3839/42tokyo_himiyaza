/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_ft_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:44:02 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:32 by himiyaza         ###   ########.fr       */
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
