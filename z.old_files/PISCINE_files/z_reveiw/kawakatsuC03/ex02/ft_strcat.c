/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:22:02 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/25 17:38:16 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
		i++;
	while (src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[20] = "conju";
	char	src[] = "nction";
	char	dest1[20] = "conju";
	char	src1[] = "nction";

	printf("%s\n", dest);
	printf("%s\n", ft_strcat(dest, src));
	printf("%s\n", dest);
	printf("\n");
	printf("%s\n", dest1);
	printf("%s\n", strcat(dest1, src1));
	printf("%s\n", dest1);
	return (0);
}
