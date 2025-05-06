/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:04:46 by ttanaka           #+#    #+#             */
/*   Updated: 2025/03/24 15:04:57 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_puzzle
{
	int	size;
	int	**grid;
	int	*clues;
	int	*seen;
}	t_puzzle;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
void	print_grid(t_puzzle *t_puzzle);
void	init_grid(t_puzzle *t_puzzle);
void	init_seen(t_puzzle *t_puzzle);
char	*ft_nums_to_str(int *nums, int size);
int		input_to_clues(t_puzzle *t_puzzle, char *str);
int		is_valid_placement(t_puzzle *t_puzzle, int r, int c, int n);
int		count_visible_buildings_up(t_puzzle *t_puzzle, int col);
int		count_visible_buildings_down(t_puzzle *t_puzzle, int col);
int		count_visible_buildings_left(t_puzzle *t_puzzle, int row);
int		count_visible_buildings_right(t_puzzle *t_puzzle, int row);
int		solve(t_puzzle *t_puzzle, int row, int col);

#endif
