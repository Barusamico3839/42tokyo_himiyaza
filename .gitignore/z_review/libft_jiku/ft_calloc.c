/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:18 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/06 23:27:54 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// mallocでメモリ確保して、全部０で初期化する関数
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

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
	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
