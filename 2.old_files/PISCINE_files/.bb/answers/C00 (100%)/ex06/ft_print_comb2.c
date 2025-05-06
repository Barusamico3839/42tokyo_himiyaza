/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:47:31 by rteles            #+#    #+#             */
/*   Updated: 2025/03/28 20:49:34 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_two_digit(int n)
{
	char	c1;
	char	c2;

	c1 = '0' + n / 10;
	c2 = '0' + n % 10;
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	print_pair(int a, int b)
{
	print_two_digit(a);
	write(1, " ", 1);
	print_two_digit(b);
	if (!(a == 98 && b == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_pair(a, b);
			b++;
		}
		a++;
	}
}

int main(void)
{
	ft_print_comb2();
	return(0);
}
