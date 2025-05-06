/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:54:29 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/06 23:34:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// putstrして最後に改行を挟む
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
// int	main(void)
// {
// 	char	*s;

// 	s = "hello";
// 	ft_putendl_fd(s, 1);
// 	return (0);
// }
