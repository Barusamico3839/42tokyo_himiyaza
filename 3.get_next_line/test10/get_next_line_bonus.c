/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:26:35 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/06 22:26:31 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_tail(char *hoge)
{
	char	*tail;
	size_t	len_all;
	size_t	i;

	i = 0;
	if (hoge == NULL)
		return (NULL);
	len_all = ft_strlen(hoge);
	while (hoge[i] != '\n' && i < len_all)
		i++;
	tail = ft_substr(hoge, i + 1, len_all - (i + 1));
	if (tail == NULL)
		return (free(tail), NULL);
	return (tail);
}

char	*extract_head_body_nl(char *hoge)
{
	char	*head_body_nl;
	int		i;

	i = 0;
	while (hoge[i] != '\n' && hoge[i] != '\0')
		i++;
	head_body_nl = ft_substr(hoge, 0, i + (hoge[i] == '\n'));
	if (head_body_nl == NULL)
		return (NULL);
	return (head_body_nl);
}

char	*read_body(int fd, char *head[fd], char *tmp)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*hoge;

	hoge = ft_strdup(head[fd] + (head[fd] == NULL) * (uintptr_t) "");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (hoge == NULL || buffer == NULL)
		return (free(hoge), free(buffer), NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && !hoge[0]))
			return (free(hoge), free(buffer), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(hoge, buffer);
		free(hoge);
		if (tmp == NULL)
			return (free(buffer), NULL);
		hoge = tmp;
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (free(buffer), hoge);
}

char	*get_next_line(int fd)
{
	static char	*head[FD_MAX];
	char		*tail;
	char		*head_body_nl;
	char		*hoge;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	hoge = read_body(fd, &head[fd], NULL);
	if (hoge == NULL)
		return (free(head[fd]), head[fd] = NULL, NULL);
	head_body_nl = extract_head_body_nl(hoge);
	if (head_body_nl == NULL)
		return (free(hoge), free(head_body_nl), free(head[fd]), head[fd] = NULL,
			NULL);
	tail = extract_tail(hoge);
	free(hoge);
	if (tail == NULL)
		return (free(tail), free(head_body_nl), free(head[fd]), head[fd] = NULL,
			NULL);
	free(head[fd]);
	head[fd] = ft_strdup(tail);
	free(tail);
	if (head[fd] == NULL)
		return (free(head_body_nl), NULL);
	return (head_body_nl);
}

// static int error_flag = 0;

// if(error_flag == 1000)
// 	return(NULL);