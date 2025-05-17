#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char *read_line(int fd, char *buffer, int *bytes_read)
{
    char *line = NULL;
    int total_bytes = 0;

    while (1)
    {
        *bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (*bytes_read <= 0)
            break;
        total_bytes += *bytes_read;
        line = realloc(line, total_bytes + 1);
        if (!line)
            return NULL;
        for (int i = 0; i < *bytes_read; i++)
            line[total_bytes - *bytes_read + i] = buffer[i];
        line[total_bytes] = '\0';
        if (line[total_bytes - 1] == '\n')
            break;
    }
    return line;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    int bytes_read = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    char *line = read_line(fd, buffer, &bytes_read);
    if (bytes_read <= 0 && (!line || line[0] == '\0'))
    {
        free(line);
        return NULL;
    }
    return line;
}