/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.stdin_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 03:24:49 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	stdin_error_check(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		ft_printf("Usage: ./so_long <map_file.ber>\n");
	is_valid_fd(argv[1], map);
}
