/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30.is_enemy_tile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:05:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:05:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_enemy_tile(char c)
{
	return (c == 'W' || c == 'X' || c == 'Y' || c == 'Z');
}
