// filepath: /get_next_line/get_next_line/get_next_line_bonus.c
#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static char *read_line(int fd, char *buffer, char **line, int *newline_found)
{
    int bytes_read;
    char *temp;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return NULL;
    buffer[bytes_read] = '\0';
    temp = *line;
    *line = malloc((temp ? strlen(temp) : 0) + bytes_read + 1);
    if (!*line)
        return NULL;
    if (temp)
    {
        strcpy(*line, temp);
        free(temp);
    }
    strcat(*line, buffer);
    if (strchr(buffer, '\n'))
        *newline_found = 1;
    return *line;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static int newline_found = 0;
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    if (newline_found)
    {
        newline_found = 0;
        return strdup(buffer);
    }

    while (1)
    {
        if (!read_line(fd, buffer, &line, &newline_found))
            break;
        if (newline_found)
            break;
    }
    return line;
}