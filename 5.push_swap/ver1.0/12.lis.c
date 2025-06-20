/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:26:46 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/18 22:05:40 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lis(int *arr_a, int *arr_lis, int i, int remainder)
{
	int	arr_lis_len[200];
	int	prev[200];
	int	j;
	int	k;
	int	max;
	int	max_idx;

	max = 1;
	max_idx = 0;
	j = 0;
	while (j < remainder)
	{
		arr_lis_len[i + j] = 1;
		prev[i + j] = -1;
		j++;
	}
	j = 0;
	while (j < remainder)
	{
		k = 0;
		if (1 /* arr_a[j] > arr_a[i] */)
		{
			while (k < j)
			{
				if (arr_a[i + k] < arr_a[i + j] && arr_lis_len[i + k]
					+ 1 > arr_lis_len[i + j])
				{
					arr_lis_len[i + j] = arr_lis_len[i + k] + 1;
					prev[i + j] = k;
				}
				k++;
			}
			if (arr_lis_len[i + j] > max)
			{
				max = arr_lis_len[i + j];
				max_idx = j;
			}
		}
		j++;
	}
	j = 0;
	while (j < remainder)
	{
		arr_lis[i + j] = 0;
		j++;
	}
	j = max_idx;
	while (j >= 0)
	{
		arr_lis[i + j] = 1;
		j = prev[i + j];
	}
	return (max);
}
void copy_arr1_to_arr2(int  *arr1, int *arr2)
{
	int i;

	i = 0;
	while (i < 200)
	{
		arr2[i] = arr1[i];
		i++;
	}
}

int	find_lis(int *arr_a, int *arr_lis)
{
	int	arr_len;
	int	starting_pos;
	int king_arr_len = 0;
	int king_arr_lis[200];

	starting_pos = 0;
	while (starting_pos < 1)
	{
		arr_len = lis(arr_a, arr_lis, starting_pos, 100);
		if( arr_len > king_arr_len )
		{
			king_arr_len = arr_len;
			copy_arr1_to_arr2(arr_lis, king_arr_lis);
		}
		starting_pos++;
	}
	copy_arr1_to_arr2(king_arr_lis, arr_lis);
	return(king_arr_len);
}
