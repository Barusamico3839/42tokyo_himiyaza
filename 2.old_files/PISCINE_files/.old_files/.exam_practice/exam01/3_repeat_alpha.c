/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_repeat_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:38:28 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:40 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		j = 0;
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			j = argv[1][i] - 'a' + 1;
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			j = argv[1][i] - 'A' + 1;
		while (j--)
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
