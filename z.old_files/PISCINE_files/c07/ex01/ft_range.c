/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:10:25 by rteles            #+#    #+#             */
/*   Updated: 2025/04/02 05:41:36 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*suuchi;

	i = 0;
	if (min >= max)
		return (0);
	suuchi = (int *)malloc((max - min) * sizeof(int));
	if (suuchi == 0)
		return (0);
	while (i < max - min)
	{
		suuchi[i] = min + i;
		i++;
	}
	return (suuchi);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	max;
// 	int	min;
// 	int	i;

// 	max = 42;
// 	min = 5;
// 	i = 0;
// 	while (i < max - min)
// 	{
// 		printf("%i ", ft_range(min, max)[i]);
// 		i++;
// 	}
// 	free(ft_range(min, max));
// }
