/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:44:20 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/19 17:29:11 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	error_check(int fd, char **leftover, char **concatenated_str)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (*leftover == NULL)
	{
		*leftover = ft_strdup("");
		if (*leftover == NULL)
			return (-1);
	}
	*concatenated_str = ft_strdup(*leftover);
	if (*concatenated_str == NULL)
		return (-1);
	return (0);
}

static char	*concatenation(char *concatenated_str, char *tenate)
{
	char	*conca;

	if (!tenate)
		return (concatenated_str);
	conca = concatenated_str;
	concatenated_str = ft_strjoin(conca, tenate);
	if (concatenated_str == NULL)
	{
		free(conca);
		free(tenate);
		return (NULL);
	}
	free(tenate);
	free(conca);
	return (concatenated_str);
}

static int	buffer_kara_find_kaigyou(ssize_t bytes_read, char **bf,
		char **concatenated_str, char **leftover, char **tenate)
{
	ssize_t	i;
	char	*leftover_tmp;
	int		kaigyou_atta;

	i = 0;
	*tenate = NULL;
	kaigyou_atta = 0;
	while (i < bytes_read)
	{
		if ((*bf)[i] == '\n')
		{
			*tenate = ft_substr(*bf, 0, i + 1);
			if (*tenate == NULL)
				return (free(*bf), free(*concatenated_str), *bf = NULL,
					*concatenated_str = NULL, -1);
			leftover_tmp = *leftover;
			*leftover = ft_substr(*bf, i + 1, bytes_read - i - 1);
			if (*leftover == NULL)
			{
				if (leftover_tmp)
					free(leftover_tmp);
				*leftover = ft_strdup("");
				if (*leftover == NULL)
					return (-1);
				return (free(*bf), free(*tenate), free(*concatenated_str),
					*bf = NULL, *tenate = NULL, *concatenated_str = NULL, -1);
			}
			return (free(leftover_tmp), free(*bf), *bf = NULL, kaigyou_atta = 1,
				kaigyou_atta);
		}
		i++;
	}
	if (i == bytes_read && kaigyou_atta == 0)
	{
		*tenate = ft_substr(*bf, 0, i);
		free(*bf);
		*bf = NULL;
		if (*tenate == NULL)
			return (free(*concatenated_str), *concatenated_str = NULL, -1);
	}
	return (kaigyou_atta);
}

static int	buffer_read(int fd, char **concatenated_str, char **leftover,
		char **buffer)
{
	ssize_t	bytes_read;

	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (*buffer == NULL)
	{
		free(*concatenated_str);
		*concatenated_str = NULL;
		return (-1);
	}
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(*buffer);
		*buffer = NULL;
		if (bytes_read == 0 && **concatenated_str != '\0')
			return (0);
		free(*concatenated_str);
		*concatenated_str = NULL;
		if (*leftover)
		{
			free(*leftover);
			*leftover = NULL;
		}
		return (-1);
	}
	(*buffer)[bytes_read] = '\0';
	return (bytes_read);
}

static int	nakami(int fd, char **leftover, char **concatenated_str)
{
	int		kaigyou_atta;
	char	*buffer;
	ssize_t	bytes_read;
	char	*tenate;

	buffer = NULL;
	kaigyou_atta = 0;
	tenate = NULL;
	while (kaigyou_atta == 0)
	{
		bytes_read = buffer_read(fd, concatenated_str, leftover, &buffer);
		if (bytes_read == -1)
			return (-1);
		kaigyou_atta = buffer_kara_find_kaigyou(bytes_read, &buffer,
				concatenated_str, leftover, &tenate);
		if (kaigyou_atta == -1)
			return (-1);
		*concatenated_str = concatenation(*concatenated_str, tenate);
		if (*concatenated_str == NULL)
			return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char *concatenated_str;
	static char *leftover = NULL;
	int error;

	concatenated_str = NULL;
	error = error_check(fd, &leftover, &concatenated_str);
	if (error == -1)
		return (NULL);
	error = nakami(fd, &leftover, &concatenated_str);
	if (error == -1)
		return (NULL);
	return (concatenated_str);
}