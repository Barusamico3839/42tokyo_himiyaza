/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2 copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:54:01 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/28 17:39:16 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	int	k=0;
	int l
	char 	c;
	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			c = '0'+ i;
			write(1, &c, 1);
			c = '0'+ j;
			write(1, &c, 1);
			write(1, ", ", 2);
			j++;
		}
		j = 0;
		i++;
	}
}
int	main(void)
{
	ft_print_comb2();
	return (0);
}
