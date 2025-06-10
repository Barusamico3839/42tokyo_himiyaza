/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:57:07 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/11 01:01:59 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_kouzoutai_maji_imifumei
{
    int             value;
    struct s_kouzoutai_maji_imifumei  *prev;
    struct s_kouzoutai_maji_imifumei  *next;
} t_node;




#endif