/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:45:56 by rteles            #+#    #+#             */
/*   Updated: 2025/03/28 21:31:52 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int value, int original, int base_power)
{
	char	digit;

	if (original < base_power)
	{
		write(1, "0", 1);
	}
	while (value != 0)
	{
		digit = (value % 10) + '0';
		write(1, &digit, 1);
		value /= 10;
	}
}

int	power(int base, int exponent)
{
	int	result;
	int	i;

	result = 1;
	if (base != 0)
	{
		i = 1;
		while (i <= exponent)
		{
			result *= base;
			i++;
		}
	}
	else
	{
		return (0);
	}
	return (result);
}

int	print_if_valid(int status, int number, int base_power)
{
	int	reversed_number;
	int	prev_digit;
	int	current_digit;
	int	temp;

	reversed_number = 0;
	prev_digit = 10;
	temp = number;
	while (temp != 0)
	{
		reversed_number *= 10;
		current_digit = (temp % 10);
		reversed_number += current_digit;
		temp /= 10;
		if (current_digit >= prev_digit)
		{
			return (-1);
		}
		prev_digit = current_digit;
	}
	print_number(reversed_number, number, base_power);
	return (status);
}

void	process_combinations(int n)
{
	int	number;
	int	base_power;
	int	max_value;
	int	first_digit;

	number = 12345678 / power(10, 9 - n);
	base_power = power(10, n - 1);
	max_value = base_power * 9;
	while (number <= max_value)
	{
		if (print_if_valid(1, number, base_power) == 1)
		{
			first_digit = number / base_power;
			if (first_digit == (10 - n))
			{
				number = max_value + 1;
			}
			else
			{
				write(1, ", ", 2);
			}
		}
		number++;
	}
}

void	ft_print_combn(int n)
{
	if ((n >= 1) && (n <= 9))
	{
		process_combinations(n);
	}
}
int main(void)
{
	ft_print_combn(2);
	return(0);
}
