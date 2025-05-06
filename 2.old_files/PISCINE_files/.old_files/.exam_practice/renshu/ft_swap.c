/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:40:45 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 18:13:53 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	moto;
	int	saki;

	moto = 123;
	printf("moto: %i\n", moto);
	ft_swap(&saki, &moto);
	printf("saki: %i\n", saki);
}
