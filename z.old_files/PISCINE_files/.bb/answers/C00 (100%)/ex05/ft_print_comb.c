/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:56:20 by rteles            #+#    #+#             */
/*   Updated: 2025/03/28 23:21:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	escrever(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (! (a == 55 && b == 56 && c == 57))
		write(1, ", ", 2);
}

void	while1(char a, char b, char c)
{
	while (a < b < c && ! (a == 55 && b == 56 && c == 57))
	{
		escrever(a, b, c);
		if (b == 56 && c == 57)
		{
			a++;
			b = a + 1;
			c = b + 1;
		}
		else if (c == 57 && b != 56)
		{
			b++;
			c = b + 1;
		}
		else if (! (a == 55 && b == 56 && c == 57))
		{
			c++;
		}
	}
	escrever(a, b, c);
}

void	ft_print_comb(void)
{
	while1(48, 49, 50);
}
int main(void)
{
	ft_print_comb();
	return(0);
}
