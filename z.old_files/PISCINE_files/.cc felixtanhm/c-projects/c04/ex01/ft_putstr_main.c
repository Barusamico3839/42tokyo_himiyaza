/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feltan <feltan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:46:22 by feltan            #+#    #+#             */
/*   Updated: 2024/03/06 09:49:11 by feltan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
}

int main(void)
{
	char str[] = "hello world";
	ft_putstr(str);
	return 0;
}
