/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:59:19 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:27:57 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 文字列s1の最初と最後からいらない文字(set)をtrimする関数、
//　s1 = "xyx helloyyx" set = "xy" trimmed_str = " hello"
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strlcpy(trimmed_str, &s1[start], end - start + 1);
	return (trimmed_str);
}
