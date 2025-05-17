#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static char *read_line(int fd, char *buffer, int *bytes_read)
{
    char *line = NULL;
    int total_bytes = 0;

    while ((*bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        total_bytes += *bytes_read;
        line = realloc(line, total_bytes + 1);
        if (!line)
            return NULL;
        line[total_bytes - *bytes_read] = '\0';
        strncat(line, buffer, *bytes_read);
        if (strchr(buffer, '\n'))
            break;
    }
    return line;
}

char *get_next_line(int fd)
{
    static char *lines[MAX_FD]; // Assuming MAX_FD is defined in the header
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    lines[fd] = read_line(fd, buffer, &bytes_read);
    if (!lines[fd])
        return NULL;

    char *line = strdup(lines[fd]);
    if (!line)
        return NULL;

    // Process line to ensure it ends with '\n' if necessary
    // and manage the static variable for the next call

    return line;
}