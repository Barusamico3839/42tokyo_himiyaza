/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:10:48 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:28:01 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//　文字列ｓのstart番目からlen分コピーして出力する。
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substring = (char *)ft_calloc(len + 1, sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
