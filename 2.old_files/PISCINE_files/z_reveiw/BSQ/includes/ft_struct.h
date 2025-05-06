/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:08:53 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/03 23:08:54 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct s_map
{
	char	empty;
	char	obs;
	char	full;
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
