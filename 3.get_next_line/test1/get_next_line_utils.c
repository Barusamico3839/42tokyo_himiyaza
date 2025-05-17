// filepath: /get_next_line/get_next_line/get_next_line_utils.c
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char *ft_strjoin(char *s1, char *s2)
{
    char *result;
    size_t len1 = 0;
    size_t len2 = 0;
    size_t i = 0;
    size_t j = 0;

    if (s1)
        while (s1[len1])
            len1++;
    if (s2)
        while (s2[len2])
            len2++;

    result = (char *)malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);

    while (i < len1)
    {
        result[i] = s1[i];
        i++;
    }
    while (j < len2)
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';

    free(s1);
    return (result);
}

static char *ft_strdup(const char *s)
{
    char *dup;
    size_t len = 0;

    while (s[len])
        len++;
    dup = (char *)malloc(len + 1);
    if (!dup)
        return (NULL);
    for (size_t i = 0; i < len; i++)
        dup[i] = s[i];
    dup[len] = '\0';
    return (dup);
}

static size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return (len);
}

// Additional utility functions can be added here as needed.