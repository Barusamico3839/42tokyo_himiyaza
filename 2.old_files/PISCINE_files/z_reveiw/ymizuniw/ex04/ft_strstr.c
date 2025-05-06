/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:22:46 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/24 18:39:40 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i] != 0)
	{
		j = 0;
		while (to_find[j] != 0 && str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
#include <stdio.h>

int	main(void)
{
	char str[] = "rush01 is too difficult";
	char to_find[] = "too";

	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
