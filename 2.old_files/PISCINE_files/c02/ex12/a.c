/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:05:09 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/19 00:07:57 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	print_memory_line(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			print_hex(addr[i]);
		else
			write(1, "  ", 2);
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (addr[i] >= 32 && addr[i] < 127)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex((unsigned long)ptr);
		ft_putchar(':');
		ft_putchar(' ');
		j = 0;
		while (j < 16)
		{
			print_memory_line(ptr + j, size - j);
			ft_putchar('\n');
			j += 16;
		}
		i += 16;
		ptr += 16;
	}
	return (addr);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	tab[10] = {0, 23, 150, 255,
// 					12, 16, 21, 42};
// 	char	*str = "Bonjour les aminches\t\n\tc  est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. ";
// 	int	tab2[10] = {0, 23, 150, 255,
// 					12, 16, 21, 42};
// 	int	tab3[10] = {0, 23, 150, 255,
// 					12, 16, 21, 42};
// 	int	tab4[10] = {0, 23, 150, 255,
// 					12, 16, 21, 42};

// 	ft_print_memory(tab, sizeof(tab));
// 	printf("\n");
// 	ft_print_memory(str, sizeof(str));
// 	printf("\n");
// 	ft_print_memory(tab2, sizeof(tab2));
// 	printf("\n");
// 	ft_print_memory(tab3, sizeof(tab3));
// 	printf("\n");
// 	ft_print_memory(tab4, sizeof(tab4));
// 	printf("\n");
// 	return (0);
// }
