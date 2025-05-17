/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:12:36 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/27 15:47:59 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char **str)
{
	int	minus_hantei;
	int	i;

	i = 0;
	minus_hantei = 1;
	while ((*str)[i] == ' ' || ((*str)[i] >= 9 && (*str)[i] <= 13))
		i++;
	while ((*str)[i] == '-' || (*str)[i] == '+')
	{
		if ((*str)[i] == '-')
			minus_hantei = minus_hantei * -1;
		i++;
	}
	*str += i;
	return (minus_hantei);
}

int	base_length_hakaru(char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len] != 0)
		base_len++;
	return (base_len);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i + 1] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	minus_hantei;
	int	i;
	int	n;
	int	base_len;

	i = 0;
	n = 0;
	base_len = base_length_hakaru(base);
	if (base_len < 2 || base_check(base) > 0)
		return (0);
	minus_hantei = check(&str);
	while (*str != 0)
	{
		i = 0;
		while (base[i] != 0 && *str != base[i])
			i++;
		if (base[i] != 0)
			n = n * base_len + i;
		else
			break ;
		str++;
	}
	return (n * minus_hantei);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*base;

// 	str = "  ---222abc12";
// 	base = "0123";
// 	printf("%i\n", ft_atoi_base(str, base));
// 	return (0);
// }
