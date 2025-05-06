/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:14:19 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/26 18:01:43 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
//
// int main(void)
// {
// 	char c1 = 'A';
// 	char c2 = '1';
// 	char c3 = '!';
// 	char c4 = ' ';
//
// 	char c5 = 'z';
// 	char c6 = '0';
// 	char c7 = '9';
// 	char c8 = 'Z';

// 	ft_isalnum(c1) ? printf("%c is alphanumeric\n", c1) : printf("%c is not alphanumeric\n", c1);

