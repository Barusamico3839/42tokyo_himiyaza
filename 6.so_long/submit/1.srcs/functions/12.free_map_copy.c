/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.free_map_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:56:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:56:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map_copy(char **gmap_copy, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(gmap_copy[y]);
		y++;
	}
	free(gmap_copy);
}
