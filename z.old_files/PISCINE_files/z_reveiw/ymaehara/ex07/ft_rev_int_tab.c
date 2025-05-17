/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:44:32 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/19 23:09:30 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	m;

	i = 0;
	while (i < size / 2)
	{
		m = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = m;
		i++;
	}
}
#include <stdio.h>

int	main(void)
{
	int	arr[] = {0, 1, 2, 3, 4, 5};
	int	size;
	int	i;

	i = 0;
	size = 6;
	printf("Before: ");
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	ft_rev_int_tab(arr, size);
	i = 0;
	printf("After: ");
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	return (0);
}
