/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:16:05 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/21 21:15:53 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_rev_print(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if arg
		while (str[size] != '\0')
			size++;
	while (i < size / 2)
	{
		ft_swap(&str[i], &str[size - i - 1]);
		i++;
	}
	return (str);
}
int	main(int argc, char **argv)
{
	// char	*a;
	// a = "abc";
	// printf("%s", ft_rev_print(a));
	printf("%s", ft_rev_print(argv[1]));
}
