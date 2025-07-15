/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.ultimate_lis_turk100.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:06:23 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/04 03:57:20 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *apply_lis_arr_to_list(int *arr_lis,t_node *stack_a)
{
	int starting_pos=0;
	int i;
	
	while(starting_pos<100)
	{
		if(arr_lis[starting_pos]==1)
		{
			arr_lis[starting_pos]=2;
			break;
		}
		stack_a = stack_a->next;
		starting_pos++;
	}
	i= 0;
	while(i < 100)
	{
		stack_a->lis_or_not = arr_lis[i + starting_pos];
		stack_a = stack_a->next;
		i++;
	}
	while(starting_pos-- > 0)
		stack_a = stack_a->prev;
	return (stack_a);
}

int	*stack_to_array(t_node *stack_a)
{
	int	*arr_a;
	int	i;

	arr_a = (int *)malloc(sizeof(int) * 200);
	if (!arr_a)
		return (NULL);
	i = 0;
	while (i < 100)
	{
		arr_a[i] = stack_a->mass;
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	while (i < 100)
	{
		arr_a[i + 100] = arr_a[i];
		i++;
	}
	return (arr_a);
}

char	*ultimate_lis_turk100(t_node *stack_a)
{
	int		*arr_a;
	int		arr_lis[100];
	int		arr_lis_len;
	// int		starting_pos;
	// char	*result;
	int		i;

	arr_a = stack_to_array(stack_a);
	arr_lis_len = super_swapped_lis(arr_a, arr_lis);
	// stack_a = apply_lis_arr_to_list(arr_lis, stack_a);
	// result = turk(arr_lis_len, stack_a);
	i=0;
	while(i < 5)
	{
		printf("%d:%d:%d\n", i, arr_lis[i], arr_a[i]);
		i++;
	}
	// i = 0;
	// while (i < 100)
	// {
	// 	printf("%d:%d\n", i, stack_a->lis_or_not);
	// 	i++;
	// 	stack_a = stack_a->next;
	// }
	printf("lis:%d\n", arr_lis_len);
	return (NULL); // ここではまだresultを返さない
}

// lisを行ってからturk法を行う
// lisの行い方
//

// ランダムな順番に並んでいる100個の数列がstack_aのmassに入っています。
// それを昇順に最小の手数で並び替えるプログラムを書きたいです。
// 使える手順はpa,pb,sa,sb,ss,ra,rb,rr,rra,rrb,rrr飲みです。
// 方法として、 チャンク法を使おうと思います。最初に99から下に数えてchunk1(13~20)分、をstack_bにpushして、
// その過程でstack_bが降順になるように並び替えます。その後、もう一度(99-chunk1)から下に数えて
// chunk2(13~20)分,をstack_bにプッシュして、これをstack_aの残りが20個以下になるまで繰り返します。
// stack_aの残りが20個以下になったらstack_aとstack_bをssを有効活用しながら同時にソートし、
// stack_a内、stack_b内がどちらも降順で並び替えられてる状況を作ります。その後、stack_bの要素をすべてpaします。
// それが終わったらstack_aは降順に0~99まで並んでいるはずです。
// そうしたらstack_aを再度bubble_swapでindex番号順に戻し、ポインターを返します。
// ここまでに使ったpa,pb,sa,sb,ss,ra,rb,rr,rra,rrb,rrrの関数を、
// pa=1,pb=2,sa-3,sb=4,ss=5,ra=6,rb=7,rr=8,rra=9,rrb=:,rrr=;に置き換えて、
// 順番通りにresultにchar*文字列として代入してください。

// これを、chunk1,chunk2,chunk3,,,,がそれぞれ13~20までのサイズでテストできるように、
// whileを回してください。分岐は10000通り超えに及ぶかもしれません。