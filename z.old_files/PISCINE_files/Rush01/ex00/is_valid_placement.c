/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_placement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:07:40 by ttanaka           #+#    #+#             */
/*   Updated: 2025/03/24 18:07:43 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid_placement(t_puzzle *t_puzzle, int r, int c, int n)
{
	if (t_puzzle->seen[r] & (1 << (n - 1)) || t_puzzle->seen[t_puzzle->size
			+ c] & (1 << (n - 1)))
		return (0);
	t_puzzle->grid[r][c] = n;
	if (c == t_puzzle->size - 1)
	{
		if (count_visible_buildings_left(t_puzzle, r) != t_puzzle->clues[2
				* t_puzzle->size + r] || count_visible_buildings_right(t_puzzle,
				r) != t_puzzle->clues[3 * t_puzzle->size + r])
		{
			t_puzzle->grid[r][c] = 0;
			return (0);
		}
	}
	if (r == t_puzzle->size - 1)
	{
		if (count_visible_buildings_up(t_puzzle, c) != t_puzzle->clues[c]
			|| count_visible_buildings_down(t_puzzle,
				c) != t_puzzle->clues[t_puzzle->size + c])
		{
			t_puzzle->grid[r][c] = 0;
			return (0);
		}
	}
	return (1);
}
