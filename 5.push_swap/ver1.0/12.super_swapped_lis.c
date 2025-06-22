/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.super_swapped_lis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:58:42 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/22 20:36:24 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int super_swapped_lis(int *arr_a,int *arr_lis)
{
    int arr_lis_len;
    // int swap;
    // int temp;
    // int skip =1;

    arr_lis_len = super_find_lis(arr_a, arr_lis);
    // swap = 0;
    // while(swap < 100)
    // {
    //     temp = arr_a[swap];
    //     arr_a[swap] = arr_a[swap + skip];
    //     arr_a[swap + skip] = temp;
        
    //     if(super_find_lis(arr_a, arr_lis) > arr_lis_len)
    //     {
    //         arr_lis_len = super_find_lis(arr_a, arr_lis);
    //         arr_lis[swap] += 10 * skip;
    //     }
    //     else
    //     {
    //         temp = arr_a[swap];
    //         arr_a[swap] = arr_a[swap + skip];
    //         arr_a[swap + skip] = temp;
    //     }
    //     swap++;
    // }
    return (arr_lis_len);
}