/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   26.ft_putnbr_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:03:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:03:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_putnbr_mlx(int n, t_map *map, int x, int y)
{
	char	buf[12];
	int		i;
	int		num;
	int		sign;

	i = 11;
	buf[i--] = '\0';
	sign = (n < 0);
	num = n;
	if (n == 0)
		buf[i--] = '0';
	if (n < 0)
		num = -n;
	while (num > 0)
	{
		buf[i--] = '0' + (num % 10);
		num /= 10;
	}
	if (sign)
		buf[i--] = '-';
	mlx_string_put(map->mlx, map->win, x, y, 0x000000, &buf[i + 1]);
}
