/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:08:30 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/27 15:19:54 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

 int main()
 {
    void *mlx;//スクリーン接続識別子

	
    mlx = mlx_init();//mlxの機能を使う前に一度呼び出す必要がある
	nakami(mlx);//nakami関数を呼び出す
  
    return (1);
 }

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// 10%の確率で失敗するmalloc
void *my_malloc(size_t size)
{
    if ((rand() % 10) < 3) // 0〜9のうち0なら失敗（10%）
    {
        fprintf(stderr, "my_malloc: allocation failed!\n");
        return NULL;
    }
    return malloc(size);
}