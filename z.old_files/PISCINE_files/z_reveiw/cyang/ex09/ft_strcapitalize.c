/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:29:03 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/28 14:19:10 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	a;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i - 1] && str[i - 1] <= 'z')
			a = 1;
		else if ('0' <= str[i - 1] && str[i - 1] <= '9')
			a = 1;
		else if ('A' <= str[i - 1] && str[i - 1] <= 'Z')
			a = 1;
		else
			a = 0;
		if ('A' <= str[i] && str[i] <= 'Z' && a == 1)
			str[i] = str[i] + 32;
		if ('a' <= str[i] && str[i] <= 'z' && a == 0)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
// if ('A' <= str[i] <= 'Z' && a == 0)there is no letters in front
//						dont do anything
//if ('a' <= str[i] <= 'z' && a == 1) there is a letter or #s in front
//       				dont do anything
#include <stdio.h>

int	main(void)
{
	char str1[] = "salut, comt tu vas ? 42mots qte-deux; cie+et+un";
		printf("%s\n", ft_strcapitalize(str1));
	return (0);
}
