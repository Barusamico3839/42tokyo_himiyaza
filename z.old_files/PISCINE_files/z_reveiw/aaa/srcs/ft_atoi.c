/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:09:02 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/03 23:09:06 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (ft_is_printable(str[i]))
		i++;
	i--;
	j = 0;
	while (str[i] && j < 2)
	{
		i--;
		j++;
	}
	j = 0;
	nb = 0;
	while (ft_is_number(str[j]) && j < i)
	{
		nb = nb * 10 + str[j] - '0';
		j++;
	}
	return (nb);
}
