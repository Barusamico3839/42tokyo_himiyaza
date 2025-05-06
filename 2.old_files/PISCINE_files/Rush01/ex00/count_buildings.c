/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_buildings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:08:15 by ttanaka           #+#    #+#             */
/*   Updated: 2025/03/24 18:08:16 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_visible_buildings_up(t_puzzle *t_puzzle, int col)
{
	int	cur_max;
	int	count;
	int	i;

	cur_max = 0;
	count = 0;
	i = 0;
	while (i < t_puzzle->size)
	{
		if (t_puzzle->grid[i][col] > cur_max)
		{
			cur_max = t_puzzle->grid[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_buildings_down(t_puzzle *t_puzzle, int col)
{
	int	cur_max;
	int	count;
	int	i;

	cur_max = 0;
	count = 0;
	i = t_puzzle->size - 1;
	while (i >= 0)
	{
		if (t_puzzle->grid[i][col] > cur_max)
		{
			cur_max = t_puzzle->grid[i][col];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_visible_buildings_left(t_puzzle *t_puzzle, int row)
{
	int	cur_max;
	int	count;
	int	i;

	cur_max = 0;
	count = 0;
	i = 0;
	while (i < t_puzzle->size)
	{
		if (t_puzzle->grid[row][i] > cur_max)
		{
			cur_max = t_puzzle->grid[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_buildings_right(t_puzzle *t_puzzle, int row)
{
	int	cur_max;
	int	count;
	int	i;

	cur_max = 0;
	count = 0;
	i = t_puzzle->size - 1;
	while (i >= 0)
	{
		if (t_puzzle->grid[row][i] > cur_max)
		{
			cur_max = t_puzzle->grid[row][i];
			count++;
		}
		i--;
	}
	return (count);
}
