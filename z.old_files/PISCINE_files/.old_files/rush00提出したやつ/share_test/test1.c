#include <unistd.h> //write関数を使うため

void	rush(int x, int y);
//関数のプロトタイプ宣言
void	ft_print_abc(int x, char startchar, char midchar, char endchar);
//関数のプロトタイプ宣言
void	ft_putchar(char c);
//関数のプロトタイプ宣言

int	main(void) // main関数
{
	rush(5, 3);
	rush(5, 1);
	rush(1, 1);
	rush(1, 5);
	rush(4, 4);
	return (0); // main関数の返り値
}

void	rush(int x, int y) // rush関数
{
	if (x > 0 && y > 0) // xとyが1以上の時
	{
		ft_print_abc(x, 'A', 'B', 'C'); // ft_print_abc関数を呼び出す
		y--;                            // yをデクリメント
		while (y > 1)
		{
			ft_print_abc(x, 'B', ' ', 'B');
			y--;
		}
		if (y > 0)
			ft_print_abc(x, 'A', 'B', 'C');
	}
	return ;
}

void	ft_print_abc(int x, char startchar, char midchar, char endchar)
{
	ft_putchar(startchar); // Aを書き出す!
	while ((x - 1) > 1)    //
	{
		ft_putchar(midchar);
		x--;
	}
	if (x > 1)
		ft_putchar(endchar);
	ft_putchar('\n');
}

void	ft_putchar(char c) // ft_putchar関数は”ｃ”を書き出す！
{
	write(1, &c, 1);
}
