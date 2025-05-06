/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:11:47 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/27 15:46:21 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i + 1] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;
	int	i;

	i = 0;
	base_length = 0;
	while (base[i])
	{
		base_length++;
		i++;
	}
	if (base_length < 2)
		return ;
	if (base_check(base) > 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= base_length)
		ft_putnbr_base(nbr / base_length, base);
	write(1, &base[nbr % base_length], 1);
}

// int	main(void)
// {
// 	int		ten_base_number;
// 	char	*besunochar;

// 	ten_base_number = -444;
// 	besunochar = "ohel";
// 	ft_putnbr_base(ten_base_number, besunochar);
// 	return (0);
// }
