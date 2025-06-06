/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:54:10 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/28 22:26:33 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;
	char	c;
	int		first;
	char	buffer[3];

	// write(1, "012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, ", 55);
	// write(1, "026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, ", 55);
	// write(1, "046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, ", 55);
	// write(1, "078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, ", 55);
	// write(1, "135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, ", 55);
	// write(1, "157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, ", 55);
	// write(1, "236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, ", 55);
	// write(1, "258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, ", 55);
	// write(1, "348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, ", 55);
	// write(1, "389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, ", 55);
	// write(1, "567, 568, 569, 578, 579, 589, 678, 679, 689, 789", 48);
	i = 0;
	first = 1;
	while (i < 9)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k <= 9)
			{
				if (first == 1)
					first = 0;
				else
					write(1, ", ", 2);
				buffer[0] = i + '0';
				buffer[1] = j + '0';
				buffer[2] = k + '0';
				write(1, buffer, 3);
				k++;
			}
			j++;
		}
		i++;
	}
}
int	main(void)
{
	ft_print_comb();
	return (0);
}
