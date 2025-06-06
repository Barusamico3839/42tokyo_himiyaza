/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:41:20 by rteles            #+#    #+#             */
/*   Updated: 2025/04/02 00:29:49 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
		return (0);
	*range = malloc((max - min) * sizeof(int));
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
// #include <stdio.h>
// int main()
// {
//     int *p;
//     int i;
// 	int t;

//     i = ft_ultimate_range(&p, 0, 20);
//     printf("%d\n", i);
// 	t=i;
//     while (i > 0)
//     {
//         printf("%d ", *p);
//         p++;
//         i--;
//     }
//     free(p-t);
// }
