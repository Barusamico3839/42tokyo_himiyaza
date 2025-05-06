/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:33:17 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/19 18:05:01 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#include <stdio.h>

int	main(void)
{
	int	nbr;

	nbr = 41;
	printf("%d\n", nbr);
	ft_ft(&nbr);
	printf("%d\n", nbr);
	return (0);
}
