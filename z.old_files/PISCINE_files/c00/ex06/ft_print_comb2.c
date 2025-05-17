/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:54:01 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/28 21:00:44 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int num)
{
	char	first_digit;
	char	second_digit;

	first_digit = '0';
	second_digit = '0';
	if (num <= 9)
	{
		second_digit = '0' + num;
	}
	else
	{
		first_digit = num / 10;
		second_digit = (num - (first_digit * 10)) + '0';
		first_digit = first_digit + '0';
	}
	write(1, &first_digit, 1);
	write(1, &second_digit, 1);
}

void	print_separator(int num)
{
	if ((num + 1) < 99)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	print_combinations(int first, int second)
{
	while (second > first && first < 99)
	{
		print_number(first);
		write(1, " ", 1);
		print_number(second);
		print_separator(first);
		if (second == 99)
		{
			first++;
			second = first + 1;
		}
		else
			second++;
	}
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	second = 1;
	while (second > first && first < 99)
	{
		print_number(first);
		write(1, " ", 1);
		print_number(second);
		print_separator(first);
		if (second == 99)
		{
			first++;
			second = first + 1;
		}
		else
			second++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
