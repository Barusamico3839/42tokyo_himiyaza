/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:03:06 by lquehec           #+#    #+#             */
/*   Updated: 2025/04/03 21:06:42 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	**ft_copy(char **array_map)
{
	char	**new_array;
	int		i;
	int		array_len;

	i = 0;
	array_len = 0;
	while (array_map[array_len])
		array_len++;
	new_array = malloc(sizeof(char *) * (array_len + 1));
	while (array_map[i])
	{
		new_array[i] = ft_strdup(array_map[i]);
		i++;
	}
	new_array[array_len] = 0;
	return (new_array);
}
//マップデータをコピーするための関数.比べる用と書き出す用
