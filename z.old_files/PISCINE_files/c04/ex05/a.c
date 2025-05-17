/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:12:36 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/24 10:15:39 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	sign;
	int	base_len;
	int	i;

	n = 0;
	sign = 1;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		i = 0;
		while (base[i] && *str != base[i])
			i++;
		if (base[i])
			n = n * base_len + i;
		else
			break ;
		str++;
	}
	return (n * sign);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "  -42";
// 	char	base[] = "0123456789";
// 	printf("%d\n", ft_atoi_base(str, base));
// 	return (0);
// }
