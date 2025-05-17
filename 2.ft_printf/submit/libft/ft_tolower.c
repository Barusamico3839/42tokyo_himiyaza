/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:26:53 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:28:05 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = "HeLLO WorlD";
// 	while (str[i] != 0)
// 	{
// 		printf("%c", ft_tolower(str[i]));
// 		i++;
// 	}
// 	#include <stdio.h>
// 	return (0);
// }
