/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:10:02 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/27 15:45:44 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	char	*mojiretsu;

// 	mojiretsu = "mojiretsu";
// 	ft_putstr(mojiretsu);
// 	return (0);
// }
