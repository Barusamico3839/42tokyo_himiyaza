#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	size_t	i;

	fd = open("with_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	// free(line);
	// return (0);
	i = 0;
	while (i < 3)
	{
		printf("%zu : %s", i + 1, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	get_next_line(-1);
	return (0);
}
