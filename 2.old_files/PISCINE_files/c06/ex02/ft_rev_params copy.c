/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:27:08 by feltan            #+#    #+#             */
/*   Updated: 2025/03/30 20:26:23 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i] = '\n';
	write(1, str, i + 1);
}

int	main(int argc, char *argv[])
{
	int	j;

	j = argc - 1;
	while (j > 0)
	{
		ft_putstr_nl(argv[j]);
		j--;
	}
	return (0);
}
