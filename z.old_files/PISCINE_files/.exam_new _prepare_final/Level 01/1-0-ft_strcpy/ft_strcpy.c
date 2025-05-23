/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 12:48:30 by angavrel          #+#    #+#             */
/*   Updated: 2025/04/04 04:03:39 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != 0)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;    // watch out for this line dont skip
	return (s1);
}

// DO NOT SUBMIT ANYTHING BELOW

#include <stdio.h>

int main(void)
{
	char str1[] = "Flavio";
	char str2[] = "Gaucho";

	printf("%s\n", str1);
	ft_strcpy(str1, str2);
	printf("%s\n", str1);
	return (0);
}
