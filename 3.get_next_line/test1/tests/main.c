#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

void test_get_next_line(int fd) {
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
}

int main() {
    int fd;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    test_get_next_line(fd);

    close(fd);
    return EXIT_SUCCESS;
}