#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;
	size_t i;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	// free(line);
	// return(0);
	i = 0;
	while (i < 40)
	{

		printf("%zu : %s", i + 1, line);
		printf("\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	get_next_line(-1);

	// fd = open("empty.txt", O_RDONLY);
    // line = get_next_line(fd);
    // if (line)
    // {
    //     printf("%zu : %s\n", i + 1, line);
    //     free(line);
    //     while ((line = get_next_line(fd)) != NULL)
    //         free(line);
    // }
    // else
    // {
    //     printf("%zu : (null)\n", i + 1);
    // }
    // close(fd);
	// get_next_line(-1);
	return (0);
}
