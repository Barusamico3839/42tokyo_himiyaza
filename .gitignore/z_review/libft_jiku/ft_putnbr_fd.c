/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:55:22 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:35:05 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_put_nbr1(int n, int fd)
{
	size_t	int_len;
	char	moji;

	int_len = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (0);
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	while (n > 9)
	{
		n = n / 10;
		int_len++;
	}
	moji = n + '0';
	write(fd, &moji, 1);
	return (int_len);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	int_len;
	int		copy_n;
	size_t	copy_int_len;
	char	moji;

	int_len = ft_put_nbr1(n, fd);
	if (n < 0)
		n = -n;
	while (int_len > 0)
	{
		copy_n = n;
		copy_int_len = int_len;
		while (copy_int_len > 1)
		{
			copy_n = copy_n / 10;
			copy_int_len--;
		}
		moji = copy_n % 10 + '0';
		write(fd, &moji, 1);
		int_len--;
	}
}
// int	main(void)
// {
// 	int	n;

// 	n = -1234;
// 	ft_putnbr_fd(n, 1);
// 	return (0);
// }
