/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:26:35 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/06 20:13:08 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_tail(char *head_body_nl_tail)
{
	char	*tail;
	size_t	len_all;
	size_t	i;

	i = 0;
	if (head_body_nl_tail == NULL)
		return (NULL);
	len_all = ft_strlen(head_body_nl_tail);
	while (head_body_nl_tail[i] != '\n' && i < len_all)
		i++;
	tail = ft_substr(head_body_nl_tail, i + 1, len_all - (i + 1));
	if (tail == NULL)
		return (free(tail), NULL);
	return (tail);
}

char	*extract_head_body_nl(char *head_body_nl_tail)
{
	char	*head_body_nl;
	int		i;

	i = 0;
	while (head_body_nl_tail[i] != '\n' && head_body_nl_tail[i] != '\0')
		i++;
	head_body_nl = ft_substr(head_body_nl_tail, 0, i
			+ (head_body_nl_tail[i] == '\n'));
	if (head_body_nl == NULL)
		return (NULL);
	return (head_body_nl);
}

char	*read_body(int fd, char *head, char *tmp)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*head_body_nl_tail;

	head_body_nl_tail = ft_strdup(head + (head == NULL) * (uintptr_t) "");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (head_body_nl_tail == NULL || buffer == NULL)
		return (free(head_body_nl_tail), free(buffer), NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && !head_body_nl_tail[0]))
			return (free(head_body_nl_tail), free(buffer), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(head_body_nl_tail, buffer);
		free(head_body_nl_tail);
		if (tmp == NULL)
			return (free(buffer), NULL);
		head_body_nl_tail = tmp;
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (free(buffer), head_body_nl_tail);
}

char	*get_next_line(int fd)
{
	static char	*head = NULL;
	char		*tail;
	char		*head_body_nl;
	char		*head_body_nl_tail;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	head_body_nl_tail = read_body(fd, head, NULL);
	if (head_body_nl_tail == NULL)
		return (free(head), head = NULL, NULL);
	head_body_nl = extract_head_body_nl(head_body_nl_tail);
	if (head_body_nl == NULL)
		return (free(head_body_nl_tail), free(head_body_nl), free(head),
			head = NULL, NULL);
	tail = extract_tail(head_body_nl_tail);
	free(head_body_nl_tail);
	if (tail == NULL)
		return (free(tail), free(head_body_nl), free(head), head = NULL, NULL);
	free(head);
	head = ft_strdup(tail);
	free(tail);
	if (head == NULL)
		return (free(head_body_nl), NULL);
	return (head_body_nl);
}

// static int error_flag = 0;

// if(error_flag == 1000)
// 	return(NULL);