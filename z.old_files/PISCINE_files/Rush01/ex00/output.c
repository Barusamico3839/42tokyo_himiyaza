/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanaka <ttanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:01:15 by ttanaka           #+#    #+#             */
/*   Updated: 2025/03/24 18:01:18 by ttanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putstr(char *str)
{
	ft_strlen(str);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	print_grid(t_puzzle *t_puzzle)
{
	int	i;

	i = 0;
	while (i < t_puzzle->size)
	{
		ft_putstr(ft_nums_to_str(t_puzzle->grid[i], t_puzzle->size));
		i++;
	}
}
