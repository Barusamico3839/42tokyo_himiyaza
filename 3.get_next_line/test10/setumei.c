/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setumei.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:26:35 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/06 17:30:07 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

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
	static int error_flag = 0;

	if(error_flag)
	{
		return(NULL);
	}
	if(head == NULL)
	{
		head_body_nl_tail = ft_strdup("");
	}
	else
	{
		head_body_nl_tail = ft_strdup(head);
		head = NULL;
	}
	if (head_body_nl_tail == NULL)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
			return (free(head_body_nl_tail), NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == -1)
		{
			free(head_body_nl_tail);
			free(buffer);
			error_flag = 1;
			free(head);
			return(NULL);
		}
		if(bytes_read == 0)
		{
			if(head_body_nl_tail[0] == '\0')
				{
				free(head_body_nl_tail);
				free(buffer);
				return (NULL);
				}
			break;
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(head_body_nl_tail, buffer);
		if (tmp == NULL)
		{
			free(head_body_nl_tail);
			return (free(buffer),NULL);
		}
		free(head_body_nl_tail);
		head_body_nl_tail = tmp;
		if (ft_strchr(buffer, '\n') != NULL)
		{
			break;
		}
	}
	free (buffer);
	return (head_body_nl_tail);
}



char	*get_next_line(int fd)
{
	static char	*head = NULL;
	char		*tail;
	char		*head_body_nl;
	char		*head_body_nl_tail;


    //head, 
    
    // head を　head_body_nl_tail に入れて
	head_body_nl_tail = read_and_add_head(fd, head, NULL);
    

    
	if (head_body_nl_tail == NULL)
		return (free(head), head = NULL, NULL); // return (NULL);
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
