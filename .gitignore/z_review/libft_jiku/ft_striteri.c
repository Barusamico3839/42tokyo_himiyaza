/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:02:08 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/06 23:35:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// string iterate. 文字列ｓの各文字に対して、関数ｆを適応し、ｓを直接変更する。
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
