// この関数は、一行づつ上から下に、左から右に、指定された文字列を出力する関数です。

#include <unistd.h> //write関数を使うため

void	rush(int x, int y);
//関数のプロトタイプ宣言
void	ft_print_abc(int x, char startchar, char midchar, char endchar);

void	ft_putchar(char c);

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
		ft_print_abc(x, 'A', 'B', 'C'); //一行目を出力する
		y--;                            // 一行目終わったから、yをデクリメント
		while (y > 1)                   // 最後の行になるまで続ける
		{
			ft_print_abc(x, 'B', ' ', 'B'); // 真ん中の行を出力する、ABCをB Bに変えるだけ
			y--;                            // 一行出力したから、yをデクリメント
		}
		if (y > 0)                          // 最後の行を出力する
			ft_print_abc(x, 'A', 'B', 'C');
	}
	return ;
}

void	ft_print_abc(int x, char startchar, char midchar, char endchar)
{
	ft_putchar(startchar); // Aを書き出す!
	while ((x - 1) > 1)    // 残りの列数が２つ以上のとき
	{
		ft_putchar(midchar); // Bを書き出す
		x--;                 //あと何列書くかを減らす、例えば、x=9の時、あと8列書く。
	}
	if (x > 1)
		ft_putchar(endchar); // 2列以上のものにはCを書き出す!
	ft_putchar('\n');        //行にABCを書き出した後、改行する
}

void	ft_putchar(char c) // ft_putchar関数は”ｃ”を書き出す！
{
	write(1, &c, 1);
}
