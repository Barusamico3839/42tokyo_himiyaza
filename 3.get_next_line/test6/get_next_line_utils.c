// filepath: /get_next_line/get_next_line/get_next_line_utils.c
#include "get_next_line.h"
#include <stdlib.h>

static char *ft_strjoin(char *s1, char *s2)
{
    char *result;
    size_t len1;
    size_t len2;
    size_t i;

    len1 = (s1) ? strlen(s1) : 0;
    len2 = (s2) ? strlen(s2) : 0;
    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    i = 0;
    if (s1)
    {
        while (*s1)
            result[i++] = *s1++;
    }
    while (*s2)
        result[i++] = *s2++;
    result[i] = '\0';
    free(s1);
    return (result);
}

static char *ft_strdup(const char *s)
{
    char *dup;
    size_t len;
    size_t i;

    len = strlen(s);
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    for (i = 0; i < len; i++)
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