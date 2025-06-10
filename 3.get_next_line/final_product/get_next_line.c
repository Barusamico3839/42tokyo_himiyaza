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
	tail = ft_substr(head_body_nl_tail, i + 1, len_all);
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
	head_body_nl = ft_substr(head_body_nl_tail, 0, i
			+ (head_body_nl_tail[i] == '\n'));
	// free(head_body_nl_tail);
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
	// free(head);
	if (head_body_nl_tail == NULL)
		return (NULL);
	while (1)
	{
		buffer = my_malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (free(head_body_nl_tail), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0) // read エラー発生時
		{
			free(buffer);
			free(head_body_nl_tail);
			return (NULL);
		}
		if (bytes_read == 0) // EOF
		{
			free(buffer);
			if (head_body_nl_tail[0] == '\0')
			{
				free(head_body_nl_tail);
				return (NULL);
			}
			return (head_body_nl_tail);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(head_body_nl_tail, buffer);
		free(buffer);
		if (tmp == NULL)
		{
			free(head_body_nl_tail);
			return (NULL);
		}
		free(head_body_nl_tail);
		head_body_nl_tail = tmp;
		if (ft_strchr(head_body_nl_tail, '\n') != NULL)
			break ;
	}
	// free(head);
	return (head_body_nl_tail);
}

char	*get_next_line(int fd)
{
	static char	*head = NULL;
	char		*tail;
	char		*head_body_nl;
	char		*head_body_nl_tail;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (head == NULL)
		head = ft_strdup("");
	head_body_nl_tail = read_and_add_to_head(fd, head, "");
	if (head_body_nl_tail == NULL)
	{
		free(head); // ★ static head の free 忘れ防止
		head = NULL;
		return (NULL);
	}
	head_body_nl = extract_head_body_nl(head_body_nl_tail);
	tail = extract_tail(head_body_nl_tail);
	free(head_body_nl_tail);
	free(head);
	head = tail;
	if (head_body_nl == NULL)
	{
		free(head);
		head = NULL;
		return (NULL);
	}
	if (*head_body_nl == '\0')
	{
		free(head_body_nl);
		free(head);
		head = NULL;
		return (NULL);
	}
	return (head_body_nl);
}
