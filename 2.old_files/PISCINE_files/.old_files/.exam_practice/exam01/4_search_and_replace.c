/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_search_and_replace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:39:57 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:40 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 4 || argv[2][1] != '\0' || argv[3][1] != '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == argv[2][0])
			write(1, &argv[3][0], 1);
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
