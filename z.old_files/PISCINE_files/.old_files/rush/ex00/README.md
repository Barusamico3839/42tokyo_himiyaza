
summery
1. a brief outline of the code
2. a more in depth outline of the code
3. the concepts we don't understand yet
4. questions we have
======================================================================
1.　a brief outline of the code


	if needed we will split the functions to as many files as we need,

1 main.c
	・エラーチェック
	・辞書ファイルを開いてパースする
	・数値を文字に変換して出力する
2 parser.c
	辞書ファイルを1行ずつ読み取って、「数字」と「単語」のセットを保存する
3 convert.c
	数字を桁ごとに分けて、対応する英語を組み合わせていく
4 print.c
	write を使って文字列を表示する
5 utils.c
	基本関数を自作する（libft の簡易版）
======================================================================
2. a more in depth outline of the code



 Step 1: main.c
	エラーチェック
	1. 引数チェック（引数の数や形式）
	  argcが2のとき、3のとき、それ以外のときで分ける

	2. 入力が数字かチェック
		int check_if_numeric

	3. 辞書を読み込む
		パースする、、、パースとはなにか！？！

	4. 数字を変換して出力
		convert_number_to_words

 Step 2: parser.c
	辞書ファイルを1行ずつ読み取って、「数字」と「単語」のセットを保存する
		・open + read で1行ずつ読む
				open + read ってなんだ！！！
		・: で分割して、数値と文字列を格納
		・空白の除去、エラー処理を忘れずに

 Step 3: convert.c
	数字を桁ごとに分けて、対応する英語を組み合わせていく　←時間かかるけどできるかも？
		・1234567 → 「1 million」「234 thousand」「567」
		・各ブロックを dict から検索して出力

 Step 4: print.c
	write を使って文字列を表示する


Step 5: utils.c
	基本関数を自作する（libft の簡易版）
		ft_strlen	文字列の長さを返す
		ft_strcmp	2つの文字列を比較する
		ft_strncmp	一部だけ比較（必要なら）
		ft_strdup	文字列のコピー（malloc使用）
		ft_atoi	数値文字列を int に変換する
		is_numeric	文字列がすべて数字か判定
		ft_isspace	空白文字の判定

ーーーーーーーーーーーーーーーーーーーーーーーーー
 必要になりそうな構造体（t_dict）

typedef struct s_dict
{
    unsigned int    number;
    char            *word;
} t_dict;

ーー構造体の使い方を学ばなければ！!!ーーーーーーーーーー
===========================================================================
3. the concepts we don't understand yet（rush 後に時間かけて各自調べます！）

		パースする、、、パースとはなにか


		open + read ってなんだ


		構造体の使い方を学ばなければ


		malloc, freeの使い方が分からない、


		closeってなんだ


		ヘッダーファイルって必要なの？なにそれ


		MAKEFILEとはなにか、


===========================================================================
4. questions we have（もし時間があったら聞いてみたいこと）


Q長いコードはどこから取りかかればいいの？
	このような大きなプロジェクトはどのファイルからつくっているのか、課題が出されたらまず何をしているのか、
	構想とかを紙に書いて考えてから取り組んでいますか？


Qチームプロジェクトはどのように取りかかればいいのか？
	どのように作業を分担して、どのように全体像を共有しているのか、
