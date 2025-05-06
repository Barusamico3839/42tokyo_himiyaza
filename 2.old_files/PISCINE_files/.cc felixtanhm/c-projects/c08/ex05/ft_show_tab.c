/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feltan <feltan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:34:28 by feltan            #+#    #+#             */
/*   Updated: 2024/03/14 16:38:58 by feltan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
}

void ft_putnbr(int nb)
{
	if(nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if(nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if(nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else {
		ft_putchar(nb + 48);
	}
}

void ft_show_tab(struct s_stock_str *par)
{
	int i = 0;

	while(par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i] != '\0')
		i++;
	return i;
}

char *ft_strdup(char *src)
{
	int len;
	int i = 0;
	char *dest;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	t_stock_str *result;

	i = 0;
	result = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	while(i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
		i++;
	}
	result[i].str = 0;
	return result;
}

int main(int argc, char **argv)
{
	struct s_stock_str *arr;

	arr = ft_strs_to_tab(argc, argv);
	ft_show_tab(arr);
	return (0);
}
