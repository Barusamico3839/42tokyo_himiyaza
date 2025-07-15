/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16.is_valid_difficulty.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:58:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:58:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_valid_difficulty(void)
{
	if (DIFFICULTY < 1 || DIFFICULTY > 3)
	{
		ft_printf("Error\nInvalid difficulty level. Must be 1, 2, or 3.\n");
		exit(1);
	}
}
