/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:45:56 by rteles            #+#    #+#             */
/*   Updated: 2025/04/04 16:25:06 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printNumbes(int value, int in, int sizeElevado)
{
	char	v;

	if (in < sizeElevado)
	{
		write(1, "0", 1);
	}
	while (value != 0)
	{
		v = (value % 10) + 48;
		write(1, &v, 1);
		value /= 10;
	}
}

int	elevado(int n, int elevado)
{
	int	value;
	int	index;

	value = 1;
	if (n != 0)
	{
		index = 1;
		while (index <= elevado)
		{
			value *= n;
			index++;
		}
	}
	else
	{
		return (0);
	}
	return (value);
}

int	print(int status, int in, int sizeElevado)
{
	int	numberInverso;
	int	valueAnterior;
	int	value;
	int	n;

	numberInverso = 0;
	valueAnterior = 10;
	n = in;
	while (n != 0)
	{
		numberInverso *= 10;
		value = (n % 10);
		numberInverso += value;
		n /= 10;
		if (value >= valueAnterior)
		{
			return (-1);
		}
		valueAnterior = value;
	}
	printNumbes(numberInverso, in, sizeElevado);
	return (status);
}

void	function(int n)
{
	int	in;
	int	sizeElevado;
	int	sizeMax;
	int	verificar;

	in = 12345678 / elevado(10, 9 - n);
	sizeElevado = elevado(10, n - 1);
	sizeMax = sizeElevado * 9;
	while (in <= sizeMax)
	{
		if (print(1, in, sizeElevado) == 1)
		{
			verificar = in / sizeElevado;
			if (verificar == (10 - n))
			{
				in = sizeMax + 1;
			}
			else
			{
				write(1, ", ", 2);
			}
		}
		in++;
	}
}

void	ft_print_combn(int n)
{
	if ((n <= 9) && (n >= 1))
	{
		function(n);
	}
}
int	main(void)
{
	int	n;

	n = 1;
	ft_print_combn(n);
	n = 2;
	ft_print_combn(n);
	n = 3;
	ft_print_combn(n);
	n = 4;
	ft_print_combn(n);
	n = 5;
	ft_print_combn(n);
	n = 6;
	ft_print_combn(n);
	n = 7;
	ft_print_combn(n);
	n = 8;
	ft_print_combn(n);
	n = 9;
	ft_print_combn(n);
	return (0);
}
