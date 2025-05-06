/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:04:21 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/19 00:07:55 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ft_putchar('\\');
			ft_putchar(hex[str[i] / 16]);
			ft_putchar(hex[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "Coucou\ntu vas bien ?";
// 	char	str2[] = "Coucou\ntu vas bien ?";
// 	char	str3[] = "Coucou\ntu vas bien ?";
// 	char	str4[] = "Coucou\ntu vas bien ?";
// 	ft_putstr_non_printable(str1);
// 	printf("\n");
// 	ft_putstr_non_printable(str2);
// 	printf("\n");
// 	ft_putstr_non_printable(str3);
// 	printf("\n");
// 	ft_putstr_non_printable(str4);
// 	printf("\n");
// 	return (0);
// }
