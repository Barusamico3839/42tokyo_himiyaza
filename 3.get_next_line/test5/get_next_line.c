/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:18:18 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/02 20:39:09 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// s1 とs2をつなげて返す関数
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	return (joined_str);
}

ssize_t	read_and_join(int fd, void *buffer, gnl_list *first)
{
	ssize_t	total_size_read;
	ssize_t	size_read;

	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read == -1)
		return (-1);
	total_size_read += size_read;
	if (buffer == NULL)
		return (total_size_read);
	first->joined_str = ft_strjoin(first->joined_str, buffer);
	return (read_and_join(fd, buffer, &first->joined_str));
}

char	*get_next_line(int fd)
{
	gnl_list *first;
	void *buffer;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_and_join(fd, buffer, &first->joined_str);
	return (first->joined_str);
}