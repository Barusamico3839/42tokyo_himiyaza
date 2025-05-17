/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_aff_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:44:55 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 16:15:06 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "a\n", 2);
	}
	else
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == 'a')
			{
				write(1, "a", 1);
				break ;
			}
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
