/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:26:35 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/03 19:12:42 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_tail(char *head_body_nl_tail)
{
	char	*tail;
	size_t	len_all;
	size_t	i;

	i = 0;
	len_all = ft_strlen(head_body_nl_tail);
	while (head_body_nl_tail[i] != '\n' && i < len_all)
		i++;
	tail = ft_substr(head_body_nl_tail, i + 1, len_all);
	free(head_body_nl_tail);
	if (tail == NULL)
		return (NULL);
	return (tail);
}

char	*extract_head_body_nl(char *head_body_nl_tail)
{
	char	*head_body_nl;
	int		i;

	i = 0;
	while (head_body_nl_tail[i] != '\n' && head_body_nl_tail[i] != '\0')
		i++;
	head_body_nl = ft_substr(head_body_nl_tail, 0, i + 1);
	free(head_body_nl_tail);
	if (head_body_nl == NULL)
		return (NULL);
	return (head_body_nl);
}

char	*read_and_add_to_head(int fd, char *head, char *tmp)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*head_body_nl_tail;

	head_body_nl_tail = ft_strdup(head);
	free(head);
	if (head_body_nl_tail == NULL)
		return (NULL);
	while (1)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (free(head_body_nl_tail), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buffer), head_body_nl_tail);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(head_body_nl_tail, buffer);
		free(buffer);
		free(head_body_nl_tail);
		head_body_nl_tail = tmp;
		if (ft_strchr(head_body_nl_tail, '\n') != NULL)
			break ;
	}
	return (head_body_nl_tail);
}

char	*get_next_line(int fd)
{
	static char	*head;
	char		*tail;
	char		*head_body_nl;
	char		*head_body_nl_tail;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	head_body_nl_tail = read_and_add_to_head(fd, head, "");
	if (head_body_nl_tail == NULL)
		return (NULL);
	head_body_nl = extract_head_body_nl(ft_strdup(head_body_nl_tail));
	tail = extract_tail(head_body_nl_tail);
	free(head);
	head = tail;
	return (head_body_nl);
}
