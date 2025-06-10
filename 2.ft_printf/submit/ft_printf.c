/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:38:15 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/06 22:13:09 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	int_len(unsigned long long n, unsigned int base,
		int negative_flag)
{
	size_t	int_len;

	int_len = 1;
	if (negative_flag)
		int_len++;
	while (n > base - 1)
	{
		n = n / base;
		int_len++;
	}
	return (int_len);
}

static int	ft_putnbr_u_x(unsigned long long n, unsigned int base,
		const char *format)
{
	size_t				length;
	unsigned long long	copy_n;
	size_t				copy_length;

	length = int_len(n, base, 0);
	while (length > 0)
	{
		copy_n = n;
		copy_length = length;
		while (copy_length > 1)
		{
			copy_n = copy_n / base;
			copy_length--;
		}
		if (*format == 'u' || *format == 'x')
			ft_putchar_fd("0123456789abcdef"[copy_n % base], 1);
		else if (*format == 'X')
			ft_putchar_fd("0123456789ABCDEF"[copy_n % base], 1);
		length--;
	}
	return (int_len(n, base, 0));
}

static int	ft_put_p(void *ptr)
{
	unsigned long long	n;
	int					count;
	char				x;

	n = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count = 2;
	x = 'x';
	count = count + ft_putnbr_u_x(n, 16, &x);
	return (count);
}

static size_t	put_c_s_d_i_u_x(va_list args, const char *format, size_t count,
		int negative_flag)
{
	char		*str;
	long int	n;

	if (*format == 'c' && ++count)
		return (ft_putchar_fd(va_arg(args, int), 1), count);
	else if (*format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else if (*format == 'd' || *format == 'i')
	{
		n = (long int)va_arg(args, int);
		ft_putnbr_fd(n, 1);
		if (n < 0 && ++negative_flag)
			n = -n;
		return (int_len(n, 10, negative_flag));
	}
	else if (*format == 'u')
		return (ft_putnbr_u_x(va_arg(args, unsigned int), 10, format));
	else
		return (ft_putnbr_u_x(va_arg(args, unsigned int), 16, format));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format != 0)
	{
		if (*format == '%' && format++)
		{
			if (*format == 'c' || *format == 's' || *format == 'd'
				|| *format == 'i' || *format == 'u' || *format == 'x'
				|| *format == 'X')
				count = count + put_c_s_d_i_u_x(args, format, 0, 0);
			else if (*format == 'p')
				count = count + ft_put_p(va_arg(args, void *));
			else if (count++ >= 0)
				ft_putchar_fd(*format, 1);
		}
		else if (++count)
			ft_putchar_fd(*format, 1);
		format++;
	}
	return (va_end(args), count);
}
