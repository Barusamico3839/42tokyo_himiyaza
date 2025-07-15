/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.super_swapped_lis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:58:42 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/04 03:47:37 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_fixed_lis(int *arr, int n, int *lis_idx, int starting_pos)
{
	int	i;
	int	j;
	int	max;
	int	lis[100];
	int	arr_index[100];
	int	max_idx;

	// 初期化: すべての要素のLIS長を1に設定
	i = 0;
	while (i < n)
	{
		lis[i] = 1;
		arr_index[i] = -1;
		lis_idx[i] = -1;
		i++;
	}
	// 配列の最初の要素（starting_pos位置）を必ずLISの最初として固定
	lis[0] = 1;
	arr_index[0] = -1;
	// 動的プログラミングでLISを計算（最初の要素から開始）
	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			// (starting_pos + j) % n の要素が (starting_pos + i) % n の要素より小さい場合
			if (arr[(starting_pos + j) % n] < arr[(starting_pos + i) % n]
				&& lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				arr_index[i] = j;
			}
			j++;
		}
		i++;
	}
	// 最大のLIS長とそのインデックスを見つける
	max = lis[0];
	max_idx = 0;
	i = 1;
	while (i < n)
	{
		if (lis[i] > max)
		{
			max = lis[i];
			max_idx = i;
		}
		i++;
	}
	// LISの要素を直接lis_idxに設定
	j = max_idx;
	while (j != -1)
	{
		if (j == 0)
			lis_idx[(j + starting_pos) % n] = 2;
		else
			lis_idx[(j + starting_pos) % n] = 1;
		j = arr_index[j];
	}
	return (max);
}

int	super_lis(int *arr_a, int *arr_lis)
{
	int arr_len;
	int starting_pos;
	int king_arr_len;
	int king_arr_lis[100] = {0};
	int king_starting_pos;

	king_arr_len = 0;
	king_starting_pos = 0;
	starting_pos = 0;
	while (starting_pos < 100)
	{
		arr_len = find_fixed_lis(arr_a, 100, arr_lis, starting_pos);
		if (arr_len > king_arr_len)
		{
			king_arr_len = arr_len;
			king_starting_pos = starting_pos;
			copy_arr(arr_lis, king_arr_lis, 100);
		}
		starting_pos++;
	}
	copy_arr(king_arr_lis, arr_lis, 100);
    arr_len = king_arr_len;
	return (arr_len);
}
