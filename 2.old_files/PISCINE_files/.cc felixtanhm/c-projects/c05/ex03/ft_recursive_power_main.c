/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feltan <feltan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:33:53 by feltan            #+#    #+#             */
/*   Updated: 2024/03/09 18:29:32 by feltan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
	int result = nb;

	if(power < 0)
		return 0;
	if(power == 0)
		return 1;
	if(power > 1)
		return (nb * ft_recursive_power(nb, (power - 1)));
	return result;
}

int main(void)
{
	int res = ft_recursive_power(2, 3);
	printf("%d", res);
	return 0;
}
