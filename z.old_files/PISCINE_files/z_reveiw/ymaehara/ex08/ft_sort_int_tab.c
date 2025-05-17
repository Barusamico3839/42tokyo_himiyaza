/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:29:57 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/19 23:12:31 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	x;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (k < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				x = tab[i];
				tab[i] = tab[j];
				tab[j] = x;
			}
			i++;
			j++;
		}
		i = 0;
		j = 1;
		k++;
	}
}
#include <stdio.h>

int	main(void)
{
	int	arr[] = {4, 3, 1, 2, 1, 34, 2, 5, 9, 28};
	int	size;
	int	i;

	size = 10;
	i = 0;
	printf("before\n");
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	ft_sort_int_tab(arr, size);
	i = 0;
	printf("\nafter\n");
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
}
