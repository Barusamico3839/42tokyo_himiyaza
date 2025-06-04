#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int	main(void)
{
	int fd;
	char *line;
	size_t i;

	srand(time(NULL));
	fd = open("test.txt", O_RDONLY);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
	line = get_next_line(fd);
	
	// printf("test:%s",line);
	i = 0;
	// printf("test2\n");
	while (line && i < 100)
	{
		printf("%zu : %s", i + 1, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}