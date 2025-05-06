/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_ft_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:44:47 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:31 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 42;
// 	b = 24;
// 	printf("a: %d, b: %d\n", a, b);
// 	ft_swap(&a, &b);
// 	printf("a: %d, b: %d\n", a, b);
// 	return (0);
// }
