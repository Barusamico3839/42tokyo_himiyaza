# ft_printf Project Documentation

This project is a reimplementation of the standard `printf` function in C, named `ft_printf`. The goal is to enhance your understanding of variadic functions and improve your programming skills.

## Project Structure

The project is organized into the following directories and files:

- **includes/**: Contains header files for the `ft_printf` library.
  - `ft_printf.h`: Function prototypes and necessary includes for the `ft_printf` library.

- **src/**: Contains the source files for the `ft_printf` implementation.
  - `ft_printf.c`: Implements the main functionality of the `ft_printf` function.
  - `ft_printf_utils.c`: Contains utility functions that support the main `ft_printf` implementation.
  - **bonus/**: Contains additional features for the `ft_printf` function.
    - `ft_printf_bonus.c`: Implements additional features as part of the bonus requirements.
    - `ft_printf_utils_bonus.c`: Contains utility functions that support the bonus features.

- **libft/**: Contains the `libft` library files.
  - `Makefile`: Build instructions for the `libft` library.
  - `libft.h`: Function prototypes and necessary includes for the `libft` library.
  - `ft_atoi.c`: Implements the `ft_atoi` function, which converts a string to an integer.
  - `ft_strlen.c`: Implements the `ft_strlen` function, which calculates the length of a string.

- **Makefile**: Build instructions for the `ft_printf` project.

## Usage

To compile the project, run `make` in the root directory. This will build the `ft_printf` library and any associated files.

## Features

- Supports the following format specifiers: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`.
- Bonus features include additional formatting options and flags.

## Contribution

Feel free to contribute to this project by adding features or improving existing functionality. Please ensure that your code adheres to the project's coding standards.

## License

This project is open-source and available for use in educational purposes.