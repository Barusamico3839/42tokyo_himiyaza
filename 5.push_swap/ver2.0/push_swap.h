/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:57:07 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/17 16:51:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_kouzoutai_maji_imifu
{
	int								content;
	int								mass;
	int								index;
	int								lis_flag;
	struct s_kouzoutai_maji_imifu	*prev;
	struct s_kouzoutai_maji_imifu	*next;
}									t_node;

int									push_swap(int argc, char **argv);
t_node								*make_list(int argc, int *elements);
void								coordinate_compression(int argc,
										t_node **stack_a);

#endif