/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:09:41 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/24 10:14:41 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Hello, World!";
// 	printf("%d\n", ft_strlen(str));
// 	return (0);
// }
