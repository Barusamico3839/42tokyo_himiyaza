/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:07:53 by ttanaka           #+#    #+#             */
/*   Updated: 2025/03/24 18:07:55 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	init_grid(t_puzzle *t_puzzle)
{
	int	i;
	int	j;

	t_puzzle->grid = (int **)malloc(sizeof(int *) * t_puzzle->size);
	i = 0;
	while (i < t_puzzle->size)
	{
		t_puzzle->grid[i] = (int *)malloc(sizeof(int) * t_puzzle->size);
		j = 0;
		while (j < t_puzzle->size)
		{
			t_puzzle->grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_seen(t_puzzle *t_puzzle)
{
	int	i;

	t_puzzle->seen = (int *)malloc(sizeof(int) * t_puzzle->size * 2);
	i = 0;
	while (i < t_puzzle->size * 2)
		t_puzzle->seen[i++] = 0;
}
