#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;
	size_t i;

	fd = open("empty", O_RDONLY);
	close(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	
	printf("test:%s",line);
	i = 0;
	printf("test2\n");
	while (line && i < 10)
	{
		printf("%zu : %s", i + 1, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
