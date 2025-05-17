/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:27:08 by feltan            #+#    #+#             */
/*   Updated: 2025/03/31 22:09:16 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	swap(char **argv, int i, int k)
{
	int		j;
	char	*temp;

	j = 0;
	while ((argv[i][j] != 0 || argv[i + k][j] != 0) && j != -1)
	{
		if (argv[i][j] != argv[i + k][j])
		{
			if (argv[i][j] > argv[i + k][j])
			{
				temp = argv[i];
				argv[i] = argv[i + k];
				argv[i + k] = temp;
				j = -2;
			}
			else
				j = -2;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i + 1 < argc)
	{
		k = 1;
		while (i + k < argc)
		{
			swap(argv, i, k);
			k++;
		}
		i++;
	}
	ft_write(argc, argv);
	return (0);
}
