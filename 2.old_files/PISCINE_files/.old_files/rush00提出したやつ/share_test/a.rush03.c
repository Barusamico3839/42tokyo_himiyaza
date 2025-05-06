/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.rush03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:37:37 by jaleman           #+#    #+#             */
/*   Updated: 2025/03/15 23:27:04 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_manager(int x, char startchar, char midchar, char endchar)
{
	ft_putchar(startchar);
	while ((x - 1) > 1)
	{
		ft_putchar(midchar);
		x--;
	}
	if (x > 1)
		ft_putchar(endchar);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_print_manager(x, 'A', 'B', 'C');
		y--;
		while (y > 1)
		{
			ft_print_manager(x, 'B', ' ', 'B');
			y--;
		}
		if (y > 0)
			ft_print_manager(x, 'A', 'B', 'C');
	}
	return ;
}
