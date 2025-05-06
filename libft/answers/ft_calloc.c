/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:12:31 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/29 16:00:51 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    size_t total_size;

    // オーバーフロー対策
    if (count > 0 && size > SIZE_MAX / count)
        return (NULL);

    total_size = count * size;

    // メモリ確保
    ptr = malloc(total_size);
    if (ptr == NULL)
        return (NULL);

    // 0で初期化
    ft_memset(ptr, 0, total_size);

    return (ptr);
}
