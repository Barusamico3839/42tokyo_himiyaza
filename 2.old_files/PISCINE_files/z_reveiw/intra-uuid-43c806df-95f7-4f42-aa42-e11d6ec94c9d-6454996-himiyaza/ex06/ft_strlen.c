/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:54:55 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/19 21:23:07 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
#include <stdio.h>

int	main(void)
{
	int		len;
	char	*a;

	a = "PISCINE";
	len = ft_strlen(a);
	printf("%d", len);
	return (0);
}
