/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:28:06 by lquehec           #+#    #+#             */
/*   Updated: 2025/04/03 21:08:27 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct s_map
{
	char	empty;
	char	obs;
	char	fill;
	char	**matrix;
	int		is_valid;
}			t_map;

typedef struct s_square
{
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
}			t_square;

#endif
