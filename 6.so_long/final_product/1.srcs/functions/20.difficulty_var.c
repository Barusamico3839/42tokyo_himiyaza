/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.difficulty_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:00:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	difficulty_var(int variable)
{
	if (variable == 1)
	{
		if (DIFFICULTY == 1)
			return (30); // Easy
		else if (DIFFICULTY == 2)
			return (22); // Normal
		else if (DIFFICULTY == 3)
			return (18); // Hard
		else
			exit(1); // Invalid difficulty
	}
	else if (variable == 2)
	{
		if (DIFFICULTY == 1)
			return (8); // Easy
		else if (DIFFICULTY == 2)
			return (4); // Normal
		else if (DIFFICULTY == 3)
			return (1); // Hard
		else
			exit(1); // Invalid difficulty
	}
	else
		exit(1);
}
