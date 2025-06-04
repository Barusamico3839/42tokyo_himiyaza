/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:26:35 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/03 00:00:58 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_char_1by1(int fd)
{
	static char	moji[1];
	ssize_t		error_hantei;

	error_hantei = read(fd, (void *)moji, 1);
	if (error_hantei == 0)
		return ("EOF");
	else if (error_hantei == -1)
		return ("eroor");
	return (&moji[0]);
}

char	*get_next_line(int fd)
{
	char moji[1];
    
	while ()
		get_char_1by1(fd)
}