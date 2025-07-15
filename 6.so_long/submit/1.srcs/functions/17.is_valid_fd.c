/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17.is_valid_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:58:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	copy_dir_name(char *directory_name)
{
	directory_name[0] = '.';
	directory_name[1] = '/';
	directory_name[2] = '3';
	directory_name[3] = '.';
	directory_name[4] = 'm';
	directory_name[5] = 'a';
	directory_name[6] = 'p';
	directory_name[7] = 's';
	directory_name[8] = '/';
}

static char	*create_stdin_path(char *argv)
{
	char	*stdin_map;
	char	directory_name[9];
	int		i;

	copy_dir_name(directory_name);
	i = 0;
	while (argv[i] && argv[i] != '\n')
		i++;
	stdin_map = malloc(9 + i + 1);
	if (!stdin_map)
	{
		ft_printf("Error\nFailed to allocate memory for stdin_map");
		exit(1);
	}
	i = -1;
	while (++i < 9)
		stdin_map[i] = directory_name[i];
	i = 0;
	while (argv[i] && argv[i] != '\n')
	{
		stdin_map[i + 9] = argv[i];
		i++;
	}
	stdin_map[i + 9] = '\0';
	return (stdin_map);
}

static int	try_open_stdin_map(char *argv, t_map *map)
{
	int		fd;
	char	*stdin_map;

	if (!argv)
		return (0);
	stdin_map = create_stdin_path(argv);
	fd = open(stdin_map, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		map->map_name = stdin_map;
		map->stdin_or_header = 1;
		return (1);
	}
	free(stdin_map);
	return (0);
}

static void	try_open_default_map(t_map *map)
{
	int	fd;

	write(2, "failed to open map file from stdin.\n", 36);
	fd = open(MAP_FILES, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		map->map_name = MAP_FILES;
		map->stdin_or_header = 0;
		return ;
	}
	ft_printf("Error\nFailed to open map file\n");
	exit(1);
}

void	is_valid_fd(char *argv, t_map *map)
{
	if (try_open_stdin_map(argv, map))
		return ;
	try_open_default_map(map);
}
