/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:29:03 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/23 21:07:30 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			if (i == 0 || (!((str[i - 1] >= 'A' && str[i - 1] <= 'z')
						|| ('0' <= str[i - 1] && str[i - 1] <= '9'))))
				str[i] -= 32;
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			if (i != 0 && ('!' <= str[i - 1] && str[i - 1] <= '~'))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
#include <stdio.h>

int	main(void)
{
	char	str1[] = "12345salut, com; 42m+o-deux; ";

	printf("%s\n", ft_strcapitalize(str1));
	return (0);
}
