/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:18:47 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/17 01:35:07 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void	ft_print_alphabet(void);

// int	main(void)
// {
// 	ft_print_alphabet();
// 	return (0);
// }

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c != '{')
	{
		write(1, &c, 1);
		c = c + 1;
	}
}
