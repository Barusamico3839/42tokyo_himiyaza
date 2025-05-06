/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 05:24:17 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/30 15:29:33 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (2);
	i = nb;
	while (ft_is_prime(i) == 0)
		i++;
	return (i);
}

// #include <stdio.h>

// int		main(void)
// {
// 	int input;
// 	input = 1234;
// 	printf("%d\n", ft_find_next_prime(input));
// }
