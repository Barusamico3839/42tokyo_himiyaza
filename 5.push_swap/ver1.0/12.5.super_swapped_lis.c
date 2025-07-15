/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.5.super_swapped_lis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:03:48 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/04 04:51:48 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	super_swapped_lis(int *arr_a, int *arr_lis)
{
	int	king_arr_len;
	int	king_arr_lis[100];
	int	temp_arr_a[200];
	int	temp_arr_lis[100];
	int	current_len;
	int	i;
	int	temp;
	int	king_swapped_times;
	int	swapped_times;

	swapped_times =0;
	// 最初にオリジナルの配列でsuper_lisを実行
	copy_arr(arr_a, temp_arr_a, 200);
	king_arr_len = super_lis(temp_arr_a, king_arr_lis);
	// 連続する要素をスワップして各々でsuper_lisを実行
	i = 0;
	while (i < 99) // 0-1, 1-2, ..., 98-99 をスワップ
	{
		// 配列をコピー
		copy_arr(arr_a, temp_arr_a, 200);
		// i番目とi+1番目をスワップ
		temp = temp_arr_a[i];
		temp_arr_a[i] = temp_arr_a[i + 1];
		temp_arr_a[i + 1] = temp;
		// 循環配列なので後半もスワップ
		temp = temp_arr_a[i + 100];
		temp_arr_a[i + 100] = temp_arr_a[i + 101];
		temp_arr_a[i + 101] = temp;
		// スワップした配列でsuper_lisを実行
		current_len = super_lis(temp_arr_a, temp_arr_lis);
		// より良い結果が得られた場合、保存
		if (current_len > king_arr_len)
		{
			king_arr_len = current_len;
			copy_arr(temp_arr_lis, king_arr_lis, 100);
		}
		i++;
		swapped_times++;
	}
	// 最終結果をarr_lisにコピー
	copy_arr(king_arr_lis, arr_lis, 100);
	return (king_arr_len);
}
// sa_arr_back(king_arr_lis, sa_count, starting_pos);
// sa_arr_back(temp_arr, sa_count, starting_pos);