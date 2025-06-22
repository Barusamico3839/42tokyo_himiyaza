/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13.lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:26:46 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/22 21:13:34 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// arr_lisは最初-1で初期化され、その項がsaされたら-10に、raされたら-1倍に、pbされたら+10000されます starting_posは＊−３です

void	copy_arr(int *src, int *dest, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	find_lis(int *arr, int n, int *lis_idx, int starting_pos)
{
	int	len[100];
	int	prev[100];
	int	max;
	int	max_idx;
	int	i;
	int	j;
	int	k;

	max = 1;
	max_idx = 0;
	i = 0;
	while (i < 100)
	{
		arr[i] = arr[i + starting_pos];
		i++;
	}
	i = 0;
	while (i < 100)
	{
		lis_idx[i] = -1;
		i++;
	}
	i = 0;
	while (i < n)
	{
		len[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		if (len[i] > max)
		{
			max = len[i];
			max_idx = i;
		}
		i++;
	}
	k = max - 1;
	i = max_idx;
	while (i >= 0)
	{
		lis_idx[k] = i;
		k--;
		i = prev[i];
	}
	return (max);
}
void	convert_idx_to_flag(int *arr_index, int *arr_flag, int starting_pos,
		int n)
{
	int	i;

    i=0;
    while(i<n)
    {
        arr_flag[i] = -1;
        i++;
    }
	i = 1;
    
	arr_flag[(arr_index[0] + starting_pos) % n] = 2;
	while (i < n && arr_index[i] != -1)
	{
		arr_flag[(arr_index[i] + starting_pos) % n] = 1;
		i++;
	}
}

int	super_find_lis(int *arr_a, int *arr_lis)
{
	int	arr_len;
	int	starting_pos;
	int	king_arr_len;
	int	king_arr_lis[100];
	int	king_starting_pos;

	king_arr_len = 0;
	king_starting_pos = 0;
	starting_pos = 0;
	while (starting_pos < 100)
	{
		arr_len = find_lis(arr_a, 100, arr_lis, starting_pos);
		if (arr_len > king_arr_len)
		{
			king_arr_len = arr_len;
            king_starting_pos = starting_pos;
			copy_arr(arr_lis, king_arr_lis, 100);
		}
		starting_pos++;
	}
	convert_idx_to_flag(king_arr_lis, arr_lis, king_starting_pos, 100);
	printf("king_starting_pos: %d\n", king_starting_pos);
	int i=0;
	while (i < 100)
	{
		arr_a[i] = arr_a[i + starting_pos];
		i++;
	}
	// copy_arr(king_arr_lis, arr_lis, 100);
	return (king_arr_len);
}
