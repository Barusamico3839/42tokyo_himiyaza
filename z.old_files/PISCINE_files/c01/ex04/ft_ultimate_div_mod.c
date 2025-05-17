/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:51:45 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/19 19:35:26 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *a / *b;
	*b = c % *b;
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	x;
// 	int	y;

// 	x = 42;
// 	y = 5;
// 	printf("x= %d,y=%d\n", x, y);
// 	ft_ultimate_div_mod(&x, &y);
// 	printf("div= %d,mod=%d\n", x, y);
// }
