/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feltan <feltan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:37:37 by felixtanhm        #+#    #+#             */
/*   Updated: 2024/03/07 11:52:02 by feltan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_rev_int_tab(int *tab, int size)
{
	int i;
	int len;

	i = 0;
	len = size - 1;

	while(i < size / 2)
	{
		ft_swap(&tab[i], &tab[len - i]);
		i++;
	}
}

int main(void)
{
	int numArr[5] = {1, 2, 3, 4, 5};

	ft_rev_int_tab(numArr, 5);
	printf("%d, %d, %d, %d,%d", numArr[0], numArr[1], numArr[2], numArr[3], numArr[4]);
	return(0);
}
