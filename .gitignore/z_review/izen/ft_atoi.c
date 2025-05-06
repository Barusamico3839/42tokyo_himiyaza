/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:30:40 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/06 19:10:20 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negative_flag;
	int	c;

	negative_flag = 1;
	c = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		negative_flag = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		c = c * 10 + nptr[i] - '0';
		i++;
	}
	c = c * negative_flag;
	return (c);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if(argc != 2)
// 		return(0);
// 	printf("ascii   %s\n", argv[1]);
// 	printf("atoi    %i\n", atoi(argv[1]));
// 	printf("ft_atoi %i\n", ft_atoi(argv[1]));
// 	return (0);
// }
