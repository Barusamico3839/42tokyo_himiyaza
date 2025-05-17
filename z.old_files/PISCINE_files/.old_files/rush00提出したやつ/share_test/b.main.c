/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaniguc <htaniguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:04:28 by htaniguc          #+#    #+#             */
/*   Updated: 2025/03/16 15:05:46 by htaniguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	rush(int x, int y);

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc < 3)
	{
		printf("Usage: %s x y\n", argv[0]);
		return (1);
	}
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	rush(x, y);
	return (0);
}
