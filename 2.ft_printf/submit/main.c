#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	r;
	int	ft_r;
	char *pointer;

	r = 0;
	ft_r = 0;
	pointer = "";
	//cspdiuxX%のテスト
	r = printf("%c\n", 't');
	ft_r = ft_printf("%c\n", 't');
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%s\n", "test");
	ft_r = ft_printf("%s\n", "test");
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%p\n", pointer);
	ft_r = ft_printf("%p\n", pointer);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%d\n", 42);
	ft_r = ft_printf("%d\n", 42);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%i\n", 42);
	ft_r = ft_printf("%i\n", 42);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%u\n", -1);
	ft_r = ft_printf("%u\n", -1);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%x\n", 42);
	ft_r = ft_printf("%x\n", 42);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%X\n", 42);
	ft_r = ft_printf("%X\n", 42);
	printf("T=%i, F=%i\n\n", r, ft_r);

	//0、最小の整数、空の文字列、NULL ポインタなどの特殊なケースをテストします。
	r = printf("%c\n", '0');
	ft_r = ft_printf("%c\n", '0');
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%s\n", "");
	ft_r = ft_printf("%s\n", "");
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%p\n", NULL);
	ft_r = ft_printf("%p\n", NULL);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%d\n", 0);
	ft_r = ft_printf("%d\n", 0);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%i\n", 0);
	ft_r = ft_printf("%i\n", 0);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%u\n", 0);
	ft_r = ft_printf("%u\n", 0);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%x\n", 0);
	ft_r = ft_printf("%x\n", 0);
	printf("T=%i, F=%i\n\n", r, ft_r);

	r = printf("%X\n", 0);
	ft_r = ft_printf("%X\n", 0);
	printf("T=%i, F=%i\n\n", r, ft_r);

	// 複数の引数/変換をテストします
	r = printf("%x%X%s\n", 10, 10, "testCase");
	ft_r = ft_printf("%x%X%s\n", 10, 10, "testCase");
	printf("T=%i, F=%i\n\n", r, ft_r);

	// 他の文字を文の前または後に配置して、文内のさまざまな変換をテストします。
	r = printf("P%xP%XP%s\n", 10, 10, "testCase");
	ft_r = ft_printf("P%xP%XP%s\n", 10, 10, "testCase");
	printf("T=%i, F=%i\n\n", r, ft_r);
}
