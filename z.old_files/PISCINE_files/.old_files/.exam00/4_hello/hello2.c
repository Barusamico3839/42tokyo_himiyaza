/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 10:27:08 by himiyaza          #+#    #+#             */
/*   Updated: 2025/03/15 10:29:37 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	write(1, "Hello World!\n", 13);
	return (0);
}
