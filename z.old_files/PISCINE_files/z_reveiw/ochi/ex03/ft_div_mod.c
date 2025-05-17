/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:10:16 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/19 18:10:11 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 42;
	b = 5;
	ft_div_mod(a, b, &c, &d);
	printf("div = %d, mod = %d\n", c, d);
	return (0);
}
