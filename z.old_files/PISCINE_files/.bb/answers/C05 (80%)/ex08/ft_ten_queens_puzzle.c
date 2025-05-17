/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:34:05 by rteles            #+#    #+#             */
/*   Updated: 2025/03/30 22:14:53 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int	g_board_size = 10;
int	g_queen[10];

void	spit_sol(void)
{
	int		i;
	char	*solchar;
	char	byte_alloc;

	byte_alloc = ' ';
	solchar = &byte_alloc;
	i = 0;
	while (i < g_board_size)
	{
		*solchar = g_queen[i] == -1 ? ' ' : g_queen[i] + 48;
		write(1, solchar, 1);
		i++;
	}
	write(1, "\n", 1);
	return ;
}

void	zero_queens(void)
{
	int	i;

	i = -1;
	while (++i < g_board_size)
		g_queen[i] = -1;
	return ;
}

int		check_house(int x, int q_id)
{
	int yy;
	int t;
	int pass;

	if (q_id == 0)
		return (1);
	pass = 1;
	yy = q_id;
	while ((--yy >= 0) && (pass == 1))
	{
		t = (x + (q_id - yy));
		if (t < g_board_size)
			pass = g_queen[yy] == t ? 0 : pass;
		t = (x - (q_id - yy));
		if (t >= 0)
			pass = g_queen[yy] == t ? 0 : pass;
		pass = g_queen[yy] == x ? 0 : pass;
	}
	return (pass);
}

int		next_house_recursive(int h)
{
	g_queen[h]++;
	if (g_queen[h] == g_board_size)
	{
		g_queen[h] = -1;
		return (-1);
	}
	if (check_house(g_queen[h], h) == 0)
		return (next_house_recursive(h));
	else
		return (g_queen[h]);
}

int		ft_ten_queens_puzzle(void)
{
	int sol_count;
	int r;

	sol_count = 0;
	zero_queens();
	r = 0;
	while ((r < g_board_size) && (r >= 0))
	{
		if (next_house_recursive(r) != -1)
			r++;
		else
			r--;
		if (r == g_board_size)
		{
			sol_count++;
			spit_sol();
			if (next_house_recursive(r - 1) == -1)
				r -= 2;
		}
	}
	return (sol_count);
}
int main (void)
{
	ft_ten_queens_puzzle();
}
