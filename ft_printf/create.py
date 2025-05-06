import os

# Define the directory structure and file contents
project_structure = {
    "includes": {
        "ft_printf.h": """\
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *format, ...);

#endif
"""
    },
    "src": {
        "ft_printf.c": """\
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    // Implementation of ft_printf
    return 0;
}
""",
        "ft_printf_utils.c": """\
#include "ft_printf.h"

// Utility functions for ft_printf
""",
        "bonus": {
            "ft_printf_bonus.c": """\
#include "ft_printf.h"

// Bonus implementation of ft_printf
""",
            "ft_printf_utils_bonus.c": """\
// Utility functions for bonus ft_printf
"""
        }
    },
    "libft": {
        "Makefile": """\
# Makefile for libft
NAME = libft.a

all:
\t@echo "Compiling libft..."
""",
        "libft.h": """\
#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>

int ft_strlen(const char *str);

#endif
""",
        "ft_strlen.c": """\
#include "libft.h"

int ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}
"""
    },
    "Makefile": """\
# Makefile for ft_printf
NAME = libftprintf.a

all:
\t@echo "Compiling ft_printf..."
""",
    "README.md": """\
# ft_printf

This project is a reimplementation of the `printf` function in C.
"""
}

# Function to create directories and files
def create_project_structure(base_path, structure):
    for name, content in structure.items():
        path = os.path.join(base_path, name)
        if isinstance(content, dict):
            os.makedirs(path, exist_ok=True)
            create_project_structure(path, content)
        else:
            with open(path, "w") as file:
                file.write(content)

# Create the project structure
base_path = "./ft_printf"
os.makedirs(base_path, exist_ok=True)
create_project_structure(base_path, project_structure)

print(f"Project structure created at {base_path}")
