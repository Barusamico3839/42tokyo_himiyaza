/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:11:09 by ttanaka           #+#    #+#             */
/*   Updated: 2025/03/24 18:11:11 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	solve(t_puzzle *t_puzzle, int row, int col)
{
	int	num;

	if (row == t_puzzle->size)
		return (1);
	if (col == t_puzzle->size)
		return (solve(t_puzzle, row + 1, 0));
	num = 1;
	while (num <= t_puzzle->size)
	{
		if (is_valid_placement(t_puzzle, row, col, num))
		{
			t_puzzle->grid[row][col] = num;
			t_puzzle->seen[row] |= (1 << (num - 1));
			t_puzzle->seen[t_puzzle->size + col] |= (1 << (num - 1));
			if (solve(t_puzzle, row, col + 1))
				return (1);
			t_puzzle->grid[row][col] = 0;
			t_puzzle->seen[row] ^= (1 << (num - 1));
			t_puzzle->seen[t_puzzle->size + col] ^= (1 << (num - 1));
		}
		num++;
	}
	return (0);
}
