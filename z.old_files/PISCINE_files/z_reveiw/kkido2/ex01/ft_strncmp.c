/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:21:14 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/26 17:50:29 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char			*s1;
	char			*s2;
	unsigned int	n;

	s1 = "abc";
	s2 = "abcd";
	n = 5;
	printf("%i\n", ft_strncmp(s1, s2, n));
	printf("↑is the difference between\n %s,\n    and\n %s\n", s1, s2);
	printf("comparing %i numbers", n);
}
