/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:09:46 by rteles            #+#    #+#             */
/*   Updated: 2025/04/02 12:36:14 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		else
		{
			write(1, "-", 1);
			nbr *= -1;
		}
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	position;

	position = 0;
	while (par[position].str != 0)
	{
		ft_putstr(par[position].str);
		ft_putnbr(par[position].size);
		write(1, "\n", 1);
		ft_putstr(par[position].copy);
		position++;
	}
}
// int	main(int argc, char **argv)
// {
// 	t_stock_str	*tab;

// 	tab = ft_strs_to_tab(argc - 1, argv + 1);
// 	if (tab == 0)
// 		return (1);
// 	ft_show_tab(tab);
// 	return (0);
// }
