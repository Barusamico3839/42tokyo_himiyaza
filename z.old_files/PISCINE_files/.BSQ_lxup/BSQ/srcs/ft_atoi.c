/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:58:15 by lquehec           #+#    #+#             */
/*   Updated: 2025/04/03 18:55:24 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_atoi(char *str)
{
	int	minus_count;
	int	modorichi;
	int	i;

	i = 0;
	modorichi = 0;
	minus_count = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		modorichi = modorichi * 10 + *str - '0';
		str++;
	}
	if (minus_count % 2)
		modorichi *= -1;
	return (modorichi);
}
