/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:20:42 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/24 00:18:25 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "marsalis";
// 	s2 = "marsupials";
// 	printf("%d\n", ft_strcmp(s1, s2));
// 	return (0);
// }
