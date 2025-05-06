/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 07:34:12 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:27:43 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 文字列ｓの各文字に対して、関数ｆを適応し、その結果を新しい文字列として戻す。
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
