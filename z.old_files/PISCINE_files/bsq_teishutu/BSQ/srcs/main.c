/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:33:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/03 15:33:01 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

void	ft_error_map(void)
{
	write(2, "map error\n", 10);
}

void	ft_exit(void)
{
	ft_error_map();
	exit(1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	argc--;
	argv++;
	while (i < argc)
	{
		ft_init(argc, argv[i]);
		if (i < argc - 1)
			ft_putchar('\n');
		i++;
	}
	if (!argc)
	{
		ft_init(argc, argv[i]);
	}
	return (0);
}
