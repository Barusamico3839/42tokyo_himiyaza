/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohmori <sohmori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:05:53 by ttanaka           #+#    #+#             */
/*   Updated: 2025/03/24 20:35:23 by sohmori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char *argv[])
{
	t_puzzle	t_puzzle;
	int			i;

	i = input_to_clues(&t_puzzle, argv[1]);
	if (argc != 2 || i != 0)
	{
		if (i == 1)
			ft_putstr_error("Error\n不正な入力です。");
		else
			ft_putstr_error("Error\nメモリの確保に失敗しました");
		return (1);
	}
	init_seen(&t_puzzle);
	init_grid(&t_puzzle);
	if (solve(&t_puzzle, 0, 0))
		print_grid(&t_puzzle);
	else
		ft_putstr_error("Error\n解が見つかりませんでした。");
	while (i < t_puzzle.size)
		free(t_puzzle.grid[i++]);
	free(t_puzzle.grid);
	free(t_puzzle.clues);
	free(t_puzzle.seen);
	return (0);
}
