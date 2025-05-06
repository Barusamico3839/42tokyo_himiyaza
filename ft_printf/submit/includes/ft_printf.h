#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h> //可変引数を扱うために必要
#include <unistd.h> //write用
#include <stdlib.h>

// Function prototype for ft_printf
int ft_printf(const char *format, ...);

// Utility function prototypes (if needed)
int ft_putchar(char c);
int ft_putstr(const char *str);
int ft_putnbr(int n);
int ft_putnbr_unsigned(unsigned int n);
int ft_puthex(unsigned int n, char format);
int ft_putptr(void *ptr);

#endif //ヘッダーファイルが複数回インクルードされるのを防ぐためのインクルードガード
