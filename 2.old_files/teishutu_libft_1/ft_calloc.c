/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:18 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:25:27 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// mallocでメモリ確保して、全部０で初期化する関数
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		ft_bzero(ptr, 1);
		return (ptr);
	}
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
