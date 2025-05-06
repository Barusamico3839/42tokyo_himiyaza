/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:11:45 by lquehec           #+#    #+#             */
/*   Updated: 2025/04/03 17:20:49 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_is_whitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}
// cがスペースか非表示文字だったら1を返すそうじゃなかったら０を返す
int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
// cがスペースかだったら1を返すそうじゃなかったら０を返す

int	ft_is_printable(char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
//表示可能な字だったら１そうじゃなかったら０
