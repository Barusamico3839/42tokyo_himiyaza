/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_rev_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:58:25 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:30 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
		i++;
	while (i > 0)
	{
		i--;
		write(1, &argv[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
