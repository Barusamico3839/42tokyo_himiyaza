// filepath: /get_next_line/get_next_line_utils_bonus.c
#include "get_next_line_bonus.h"
#include <stdlib.h>

static char *ft_strdup(const char *s1)
{
    char *copy;
    size_t len = 0;

    while (s1[len])
        len++;
    copy = (char *)malloc(len + 1);
    if (!copy)
        return (NULL);
    for (size_t i = 0; i < len; i++)
        copy[i] = s1[i];
    copy[len] = '\0';
    return (copy);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *joined;
    size_t len1 = 0;
    size_t len2 = 0;

    while (s1 && s1[len1])
        len1++;
    while (s2 && s2[len2])
        len2++;
    joined = (char *)malloc(len1 + len2 + 1);
    if (!joined)
        return (NULL);
    for (size_t i = 0; i < len1; i++)
        joined[i] = s1[i];
    for (size_t j = 0; j < len2; j++)
        joined[len1 + j] = s2[j];
    joined[len1 + len2] = '\0';
    free(s1);
    return (joined);
}

// Additional utility functions for bonus features can be added here.