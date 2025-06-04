#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;
	size_t i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	i = 0;
	while (line && i < 10)
	{
		printf("%zu : %s", i + 1, line);
		// free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
