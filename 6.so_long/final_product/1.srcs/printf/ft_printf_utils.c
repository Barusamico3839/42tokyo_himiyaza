/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:37:19 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/25 23:01:52 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen2(s));
}

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
	size_t int_len;
	int copy_n;
	size_t copy_int_len;
	char moji;

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